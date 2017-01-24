#!/usr/bin/env python3

import argparse


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
# Read in the binary files and output the merged binary
#
#******************************************************************************
#def process(boot_loader_filename, app_filename,  output):
def process(load_address, app_filename, app_ver, bin_type, str_type, output):

    # Open the file, and read it into an array of integers.
    with open(app_filename, mode = 'rb') as f_app:
        app_binarray = f_app.read()
        f_app.close()

    app_length  = len(app_binarray)

    pad_length  = 48;   #fixed header length
    print("pad_length ",pad_length);

    #generate mutable byte array for the boot loader
    pad_binarray = bytearray([0]*pad_length);

    # Insert encryption flag, always 0
    pad_binarray[0]  = 0x00;
    pad_binarray[1]  = 0x00;
    pad_binarray[2]  = 0x00;
    pad_binarray[3]  = 0x00;
    
    # Insert the application binary load address.
    loadaddress = int(load_address,16)
    print("load_address ",hex(loadaddress), "(",load_address,")")
    pad_binarray[4]  = (loadaddress >>  0) & 0x000000ff;
    pad_binarray[5]  = (loadaddress >>  8) & 0x000000ff;
    pad_binarray[6]  = (loadaddress >> 16) & 0x000000ff;
    pad_binarray[7]  = (loadaddress >> 24) & 0x000000ff;


    # put the application binary size into the padding array @ 0x3c04
    app_length  = len(app_binarray)
    print("app_size ",hex(app_length), "(",app_length,")")
    pad_binarray[8]   = (app_length >>  0) & 0x000000ff
    pad_binarray[9]   = (app_length >>  8) & 0x000000ff
    pad_binarray[10]  = (app_length >> 16) & 0x000000ff
    pad_binarray[11]  = (app_length >> 24) & 0x000000ff

    # compute the CRC for the application and write it to 0x3c08
    app_crc = crc32(app_binarray)
    print("crc =  ",hex(app_crc));
    pad_binarray[12]  = (app_crc >>  0) & 0x000000ff
    pad_binarray[13]  = (app_crc >>  8) & 0x000000ff
    pad_binarray[14]  = (app_crc >> 16) & 0x000000ff
    pad_binarray[15]  = (app_crc >> 24) & 0x000000ff

    # override gpio. default -1 (ignored)
    pad_binarray[16] = 0xff
    pad_binarray[17] = 0xff
    pad_binarray[18] = 0xff
    pad_binarray[19] = 0xff

    # override polarity. default 0
    pad_binarray[20] = 0

    # copy the reset vector stack pointer (SP) from the application binary to pad_binary
    pad_binarray[24] = app_binarray[0];
    pad_binarray[25] = app_binarray[1];
    pad_binarray[26] = app_binarray[2];
    pad_binarray[27] = app_binarray[3];

    # copy the reset vector program counter (PC) from the application binary to pad_binary
    pad_binarray[28] = app_binarray[4];
    pad_binarray[29] = app_binarray[5];
    pad_binarray[30] = app_binarray[6];
    pad_binarray[31] = app_binarray[7];
	
	# rma: application software version here
    print("app_ver",int(app_ver,16), "(",app_ver,")")
    appver = int(app_ver,16)
    pad_binarray[32]  = (appver >>  0) & 0x000000ff;
    pad_binarray[33]  = (appver >>  8) & 0x000000ff;
    pad_binarray[34]  = (appver >> 16) & 0x000000ff;
    pad_binarray[35]  = (appver >> 24) & 0x000000ff;
	
	# rma: binary type here
    print("bin_type",int(bin_type,16), "(",bin_type,")")
    bintype = int(bin_type,16)
    pad_binarray[36]  = (bintype >>  0) & 0x000000ff;
    pad_binarray[37]  = (bintype >>  8) & 0x000000ff;
    pad_binarray[38]  = (bintype >> 16) & 0x000000ff;
    pad_binarray[39]  = (bintype >> 24) & 0x000000ff;
	
    # rma: storage type here, 0 = internal, 1 = external
    print("str_type",int(str_type,16), "(",str_type,")")
    strtype = int(str_type,16)
    if strtype != 0:
        strtype = 1
    pad_binarray[40] = (strtype >>  0) & 0x000000ff;
    pad_binarray[41] = (strtype >>  8) & 0x000000ff;
    pad_binarray[42] = (strtype >> 16) & 0x000000ff;
    pad_binarray[43] = (strtype >> 24) & 0x000000ff;
	
	# rma: word RFU
    pad_binarray[44] = 0xff
    pad_binarray[45] = 0xff
    pad_binarray[46] = 0xff
    pad_binarray[47] = 0xff
	
    # now output all three binary arrays in the proper order
    with open(output + '.bin', mode = 'wb') as out:
        out.write(pad_binarray)
        out.write(app_binarray)

def parse_arguments():
    parser = argparse.ArgumentParser(description =
                     'Combine two binary files in to a single download.')

    # parser.add_argument('--bootbin', dest='bootbin', default='../../../../apollo_evk_base/examples/multi_boot/keil/bin/multi_boot.bin',
                        # help='Bootloader binary file (multi_boot.bin)')
                        
    parser.add_argument('--load-address', dest='loadaddress', default='0x4000',
                        help='Load address of the application.')

    parser.add_argument('--appbin', dest='appbin', default='../keil/bin/exactle_fit_amota.bin',
                        help='Application binary file (app.bin)')
                        
    #rma: add arg version        	
    parser.add_argument('--version', dest='app_ver', default='0x0',
                        help = 'Software version of the OTA image.')
    
    #rma: add arg binary type        	
    parser.add_argument('--binary-type', dest='bin_type', default='0x0',
                        help = 'Binary type to be tranferred OTA.')
                                                    
    #rma: add arg binary type        	
    parser.add_argument('--storage-type', dest='str_type', default='0x0',
                        help = 'Storage type to for the image OTA.')

    parser.add_argument('-o', dest = 'output', default = 'binary_array',
                        help = 'Output filename (without the extension)')

    args = parser.parse_args()

    return args

#******************************************************************************
#
# Main function.
#
#******************************************************************************
def main():
    # Read the arguments.
    args = parse_arguments()

    process(args.loadaddress, args.appbin, args.app_ver, args.bin_type, args.str_type, args.output)

if __name__ == '__main__':
    main()
