#!/usr/bin/env python3

import sys
import os.path
from pathlib import Path
import argparse
import time
import telnetlib

ocd = None

#******************************************************************************
#
# CRC function that matches the CRC used by the Apollo bootloader.
#
#******************************************************************************
poly32 = 0x1EDC6F41
def crc32(L):
    rem = 0
    for b in L:
        rem = rem ^ (b << 24)
        for i in range(8):
            if rem & 0x80000000:
                rem = ((rem << 1) ^ poly32)
            else:
                rem = (rem << 1)

            rem = rem & 0xFFFFFFFF
    return rem

#******************************************************************************
#
# Wait for OpenOCD to give us a prompt.
#
#******************************************************************************
def read_to_prompt():
    response = ocd.read_until(b'> ').decode('utf-8')
    return response

#******************************************************************************
#
# Send a command to openocd.
#
#******************************************************************************
def send_ocd_command(command):
    print(command)
    ocd.write(bytes(command + '\n', encoding = 'utf-8'))
    response = ocd.read_until(b'> ').decode('utf-8')
    return response

# Split OTA file into flag page, and binary file.
def split_otafile(app_filename, fname3c00, splitfile):

    # Flag page length in bytes. (0x3c00)
    flag_page_length  =  36;

    print("flag_page_length ", flag_page_length);

    #generate mutable byte array for the boot loader
    pad_binarray = bytearray([0]*flag_page_length);

    print("pad_binarray length =  ", len(pad_binarray));
    
    # Open the file, and read header into pad, and the rest into app.
    # The 4 byte encryption type is part of the 36 bytes.
    # It does not go to the 0x3c00 flag area.
    with open(app_filename, mode = 'rb') as f_app:
        enc_binarray = f_app.read(4)
        pad_binarray = f_app.read(flag_page_length-4)
        app_binarray = f_app.read()
        f_app.close()

    # Put some error checking in here...
    if int.from_bytes(enc_binarray, byteorder='little') == 0:
        print("Non-encrypted binary")
    else:
        print("Unsupported File OTA file.")

    # Get Load Address from header.
    # Insert the application binary load address.
    load_address = int.from_bytes(pad_binarray[0:3], byteorder='little', signed=False)
    print("load_address ", hex(load_address), "(",load_address,")")

    # Load byte array OTA file header.
    
    print("Creating binary flag array file %s.OTA" % fname3c00);

    path = os.getcwd();
    # now output both binary arrays in the proper order
    with open(path + '/' + fname3c00, mode = 'wb') as out:
        out.write(pad_binarray)
        out.close()

    with open(splitfile, mode = 'wb') as out:
        out.write(app_binarray)
        out.close()
    return load_address

# Generate the flag page from OTA like header data.
def generate_flag_array(app_binarray, load_address, overridegpio, overridepolarity, options, storageaddress):
    if overridegpio > 255:
        print("Override gpio out of range %d" % overridegpio)
        return False
    if overridepolarity > 255:
        print("Override polarity out of range: %d" % overridepolarity)
        return False

    # Flag page length in bytes. (0x3c00)
    flag_page_length  =  36 + 8;

    print("flag_page_length ", flag_page_length);

    #generate mutable byte array for the boot loader
    pad_binarray = bytearray([0]*flag_page_length);

    print("pad_binarray length =  ", len(pad_binarray ));

    # Insert the application binary load address.
    la = int(load_address,16)
    print("load_address ",hex(la), "(",la,")")
    pad_binarray[0]  = (la >>  0) & 0x000000ff
    pad_binarray[1]  = (la >>  8) & 0x000000ff
    pad_binarray[2]  = (la >> 16) & 0x000000ff
    pad_binarray[3]  = (la >> 24) & 0x000000ff

    # put the application binary size into the padding array @ 0x3c04
    app_length  = len(app_binarray)
    print("app_size ",hex(app_length), "(",app_length,")")
    pad_binarray[4]  = (app_length >>  0)   & 0x000000ff
    pad_binarray[5]  = (app_length >>  8)   & 0x000000ff
    pad_binarray[6]  = (app_length >> 16)   & 0x000000ff
    pad_binarray[7]  = (app_length >> 24)   & 0x000000ff

    # compute the CRC for the application and write it to 0x3c08
    app_crc = crc32(app_binarray)
    print("crc =  ",hex(app_crc));
    pad_binarray[8]  = (app_crc >>  0) & 0x000000ff
    pad_binarray[9]  = (app_crc >>  8) & 0x000000ff
    pad_binarray[10] = (app_crc >> 16) & 0x000000ff
    pad_binarray[11] = (app_crc >> 24) & 0x000000ff

    # override gpio. default 0
    print("Override GPIO", hex(overridegpio))
    pad_binarray[12] = (overridegpio >>  0) & 0x000000ff
    pad_binarray[13] = (overridegpio >>  8) & 0x000000ff
    pad_binarray[14] = (overridegpio >> 16) & 0x000000ff
    pad_binarray[15] = (overridegpio >> 24) & 0x000000ff

    # override polarity. default 0
    print("Override Polarity", overridepolarity)
    pad_binarray[16] = overridepolarity;
    pad_binarray[17] = 0;
    pad_binarray[18] = 0;
    pad_binarray[19] = 0;
    
    # copy the reset vector stack pointer (SP) from the application binary to pad_binary
    pad_binarray[20] = app_binarray[0];
    pad_binarray[21] = app_binarray[1];
    pad_binarray[22] = app_binarray[2];
    pad_binarray[23] = app_binarray[3];

    # copy the reset vector program counter (PC) from the application binary to pad_binary
    pad_binarray[24] = app_binarray[4];
    pad_binarray[25] = app_binarray[5];
    pad_binarray[26] = app_binarray[6];
    pad_binarray[27] = app_binarray[7];
	
    # rma: boot options
    op = int(options,16)
    print("Boot Options", hex(op))
    pad_binarray[28] = (op >>  0) & 0x000000ff
    pad_binarray[29] = (op >>  8) & 0x000000ff
    pad_binarray[30] = (op >> 16) & 0x000000ff
    pad_binarray[31] = (op >> 24) & 0x000000ff
	
    # rma: storage address
    saddr = int(storageaddress,16)
    print("Image Storage Address", hex(saddr))
    pad_binarray[32] = (saddr >>  0) & 0x000000ff
    pad_binarray[33] = (saddr >>  8) & 0x000000ff
    pad_binarray[34] = (saddr >> 16) & 0x000000ff
    pad_binarray[35] = (saddr >> 24) & 0x000000ff
	
    return pad_binarray


#******************************************************************************
#
# Read in the binary files and output the merged binary
#
#******************************************************************************
def generate_flag_page(app_filename, load_address, fname3c00, overridegpio, overridepolarity, options, storageaddress):

    # Open the file, and read it into an array of integers.
    with open(app_filename, mode = 'rb') as f_app:
        app_binarray = f_app.read()
        f_app.close()

    pad_binarray = generate_flag_array(app_binarray, load_address,
                    overridegpio, overridepolarity, options, storageaddress)
    if not pad_binarray:
        print("Error creating binary flag array file %s." % fname3c00);
        return False

    print("Creating binary flag array file %s." % fname3c00);

    path = os.getcwd();
    # now output both binary arrays in the proper order
    with open(os.path.join(os.getcwd(), fname3c00), mode = 'wb') as out:
        out.write(pad_binarray)
    return True

# Create golden image to load into flash.
def createimage(args):
    flagaddress = int(args.flagaddress)
    # Validate the three files we have to load.
    boot_length = ota_length = app_length = 0
    # Open the file, and read it into an array of integers.
    fn_boot = Path(args.bootbin)
    if fn_boot.is_file():
        with fn_boot.open(mode = 'rb') as f_boot:
            boot_binarray = f_boot.read()
            f_boot.close()
        boot_length  = len(boot_binarray)
        print("boot_size ",hex(boot_length), "(",boot_length,")")
        if boot_length > args.flagaddress:
            print("bootloader too large ", hex(boot_length), "> args.flagaddress")
            sys.exit(2)
        elif boot_length == 0:
            print("bootloader file empty ", hex(boot_length))
            sys.exit(2)
    else:
        print("Required bootloader file %s not found." % fn_boot)
        exit(2)

    fn_ota = Path(args.otabin)
    if fn_ota.is_file():
        with fn_ota.open(mode = 'rb') as f_ota:
            ota_binarray = f_ota.read()
            f_ota.close()
        ota_length  = len(ota_binarray)
        print("ota_size ",hex(ota_length), "(",ota_length,")")
        if ota_length == 0:
            print("otaloader file empty ", hex(ota_length))
    else:
        print("OTAloader file %s not found." % fn_ota)

    fn_app = Path(args.appbin)
    if fn_app.is_file():
        with fn_app.open(mode = 'rb') as f_app:
            app_binarray = f_app.read()
            f_app.close()
        app_length  = len(app_binarray)
        print("app_size ",hex(app_length), "(",app_length,")")
        if app_length == 0:
            print("application file empty ", hex(app_length))
    else:
        print("Application file %s not found." % fn_app)
    # Calculate total image size
    maxota_address = maxapp_address = 0
    min_length = args.flagaddress + 8*4

    # boot_length < min_length
    if ota_length:
        maxota_address = ota_length + args.otaaddress
    if app_length:
        maxapp_address = app_length + args.appaddress
    total_length = max([min_length, maxota_address, maxapp_address])
    print("Image file ", args.imgbin, "size ", hex(total_length),"(", total_length, ")")
    # todo check for overlap
    
    # Calculate flag page values.
    # Select app. If no app, ota.
    pad_binarray = False
    if app_length:
        pad_binarray = generate_flag_array(app_binarray, args.appaddress,
                        args.overridegpio, args.overridepolarity)
    elif ota_length:
        pad_binarray = generate_flag_array(ota_binarray, args.otaaddress,
                        args.overridegpio, args.overridepolarity)

    # Create the image, 0xFF where not written.
    #generate mutable byte array for the image file.
    img_binarray = bytearray([0]*total_length);
    for i in range(total_length):
        img_binarray[i] = 0xFF
    startaddr = 0
    for i in range(boot_length):
        img_binarray[startaddr] = boot_binarray[i]
        startaddr += 1
    if pad_binarray:
        startaddr = args.flagaddress
        for i in range(36):
            img_binarray[startaddr] = pad_binarray[i]
            startaddr += 1
    startaddr = args.otaaddress
    for i in range(ota_length):
        img_binarray[startaddr] = ota_binarray[i]
        startaddr += 1
    startaddr = args.appaddress
    for i in range(app_length):
        img_binarray[startaddr] = app_binarray[i]
        startaddr += 1

    fn_imgbin = Path(args.imgbin)
    with fn_imgbin.open(mode = 'wb') as f_imgbin:
        f_imgbin.write(img_binarray)
        f_imgbin.close()


#******************************************************************************
#
# Program the flash with a binary file.
#
#******************************************************************************
def program_flash(filename, address="0x0000"):
    absname = os.path.abspath(filename)
    absname = absname.replace('\\', '/')
    send_ocd_command("halt")
    send_ocd_command("reset halt")
    send_ocd_command("flash write_image erase %s %s" % (absname, address))
    send_ocd_command("verify_image  %s %s" % (absname, address))
    send_ocd_command("reset")

    print("Flash programming complete",absname," at ", address)

    return


def parse_arguments():
    commandhelp = 'Command to execute [install|installota|gen3c00|copytoFC00|bootloader]'
    parser = argparse.ArgumentParser(description =
                     'Load example to flash launched by bootloader on reset.')

    parser.add_argument('-b', dest='binfile', default = 'example.bin',
                        help = 'Application binary file to read in as input.')

    parser.add_argument('-l', dest='load_address', default = '0x8000',
                        help = 'Starting or Load address for this binary.')

    parser.add_argument('--bootbin', dest='bootbin', default='ios_boot.bin',
                        help='Bootloader binary file (ios_boot.bin)')

    parser.add_argument('--appbin', dest='appbin', default='mbapp.bin',
                        help='Application binary file (mbapp.bin)')

    parser.add_argument('--fname3c00', dest='fname3c00', default='yoda_local.OTA',
                        help='Flag page binary file (yoda_local.OTA)')

    parser.add_argument('--appaddress', dest='appaddress', default = 0x10000, type = int,
                        help='Application address (0x10000)')

    parser.add_argument('--otabin', dest='otabin', default='da14581_loader.bin',
                        help='OTAloader binary file (da14581_loader.bin)')

    parser.add_argument('--otaaddress', dest='otaaddress', default = 0x8000, type = int,
                        help='OTAloader address (0x8000)')

    parser.add_argument('--flagaddress', dest='flagaddress', default = 0x3C00,
                        help='Flag page address (0x3C00|0xFC00)')

    parser.add_argument('--imgbin', dest='imgbin', default='golden_master.bin',
                        help='Master binary file to output (golden_master.bin).')
    parser.add_argument('--override-gpio', dest='overridegpio', default=0, type = int,
                        help = 'Override GPIO number. (Can be used to force a new image load)\n(-1 to disable)')

    parser.add_argument('--override-polarity', dest='overridepolarity', default=0, type=int,
                        help = 'Polarity for the override pin.')
	#rma: add arg options					
    parser.add_argument('--boot-options', dest='options', default='0xffffffff',
                        help = 'Indicate the presence of an available new image.')						
	#rma: add arg storage address					
    parser.add_argument('--storage-address', dest='storageaddress', default='0xffffffff',
                        help = 'Storage address of the new image.')

    parser.add_argument('-r', dest='remotehost', default = 'localhost',
                        help = 'Host where openocd is running.')

    parser.add_argument('-p', dest='port', default=4444,
                        help = 'Port openocd is listening to (telnet).')

    parser.add_argument('commands', nargs='+',
                        help=commandhelp)

    args = parser.parse_args()

    return args

#******************************************************************************
#
# Main function.
#
#******************************************************************************
def main():
    global ocd
    retval = True

    # Read the arguments.
    args = parse_arguments()

    # Open a connection to OpenOCD, and wait for it to prompt us.
    try:
        ocd = telnetlib.Telnet(host=args.remotehost, port=args.port)
    except Exception as e:
        print("Telnet error({0}): {1}".format(e.errno, e.strerror))
        print("Connection to OpenOCD at %s:%d failed." % (args.remotehost, args.port))
        exit(1)
        
    read_to_prompt()

    # Read the command and run it
    for command in args.commands:
        if command =='install':
            # generate flag page array to write to 0x3c00.
            retval = generate_flag_page(args.binfile, args.load_address, args.fname3c00,
                args.overridegpio, args.overridepolarity, args.options, args.storageaddress)
            # Put the execute only bin in flash, program 0x3c00 with yoda_local.
            if retval:
                program_flash(args.binfile, args.load_address)
                program_flash(args.fname3c00, args.flagaddress)
        elif command =='gen3C00':
            # generate flag page array to write to 0x3c00.
            retval = generate_flag_page(args.binfile, args.load_address, args.fname3c00,
                args.overridegpio, args.overridepolarity, args.options, args.storageaddress)
        elif command == 'copytoFC00':
            send_ocd_command("halt")
            send_ocd_command("reset halt")
            send_ocd_command("dump_image %s.copyto 0x3c00 44" % args.fname3c00)
            send_ocd_command("flash write_image erase %s.copyto 0xFC00" % args.fname3c00)
            send_ocd_command("verify_image %s.copyto 0xFC00" % args.fname3c00)
            send_ocd_command("reset")
        elif command == 'copyto3C00':
            program_flash(args.fname3c00, 0x3C00)
            #send_ocd_command("halt")
            #send_ocd_command("reset halt")
            #send_ocd_command("dump_image %s.copyto 0x3c00 44" % args.fname3c00)
            #send_ocd_command("flash write_image erase %s 0x3C00" % args.fname3c00)
            #send_ocd_command("verify_image %s 0x3C00" % args.fname3c00)
            #send_ocd_command("reset")			
        elif command =='installota':
            # Split the ota file then write the components.
            splitbinfile = args.binfile + ".bin"
            load_address = split_otafile(args.binfile, args.fname3c00, splitbinfile)
            program_flash(splitbinfile, hex(load_address))
            program_flash(args.fname3c00, args.flagaddress)
        elif command == 'bootloader':
            # Put the bootloader in flash at 0.
            program_flash(args.bootbin, "0x0000")
        elif command == 'createimage':
            createimage(args)
        else:
            print("Unknown command: %s" % cmd)
            print("Exiting...")
            exit(2)

    # Check if flag page was generated.
    if not retval:
        print("Error generating flag page binary %s." % args.fname3c00)
        exit(1)

if __name__ == '__main__':
    main()
