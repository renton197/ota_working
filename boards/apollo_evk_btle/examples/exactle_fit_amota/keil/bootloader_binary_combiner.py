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
def process(boot_loader_filename, app_filename,  output, bin_type, load_address, 
            overridegpio, overridepolarity, versionnew, binarytype, storagetype):

    # Open the file, and read it into an array of integers.
    with open(boot_loader_filename, mode = 'rb') as f_bl:
        boot_loader_binarray = f_bl.read()
        f_bl.close()

    # Open the file, and read it into an array of integers.
    with open(app_filename, mode = 'rb') as f_app:
        app_binarray = f_app.read()
        f_app.close()

    if bin_type == 'boot':
        boot_length = len(boot_loader_binarray)
        print("boot size ",boot_length)
        if boot_length > 16383:
	        print("ERROR boot loader image is too big");
	        return

        app_length  = len(app_binarray)

        pad_length = 0x4000 - len(boot_loader_binarray)

        # this is where we will write the application size in FLASH
        flag_page_location = 0x3c00 - len(boot_loader_binarray)
        print("pad_length ",pad_length);

        #generate mutable byte array for the boot loader
        pad_binarray = bytearray([0]*pad_length);

        # Insert the application binary load address.
        print("load_address ",hex(load_address), "(",load_address,")")
        pad_binarray[flag_page_location + 0]  = (load_address >>  0) & 0x000000ff;
        pad_binarray[flag_page_location + 1]  = (load_address >>  8) & 0x000000ff;
        pad_binarray[flag_page_location + 2]  = (load_address >> 16) & 0x000000ff;
        pad_binarray[flag_page_location + 3]  = (load_address >> 24) & 0x000000ff;

        # put the application binary size into the padding array @ 0x3c04
        app_length  = len(app_binarray)
        print("app_size ",hex(app_length), "(",app_length,")")
        pad_binarray[flag_page_location + 4]  = (app_length >>  0) & 0x000000ff
        pad_binarray[flag_page_location + 5]  = (app_length >>  8) & 0x000000ff
        pad_binarray[flag_page_location + 6]  = (app_length >> 16) & 0x000000ff
        pad_binarray[flag_page_location + 7]  = (app_length >> 24) & 0x000000ff

        # compute the CRC for the application and write it to 0x3c08
        app_crc = crc32(app_binarray)
        print("crc =  ",hex(app_crc));
        pad_binarray[flag_page_location + 8]  = (app_crc >>  0) & 0x000000ff
        pad_binarray[flag_page_location + 9]  = (app_crc >>  8) & 0x000000ff
        pad_binarray[flag_page_location + 10] = (app_crc >> 16) & 0x000000ff
        pad_binarray[flag_page_location + 11] = (app_crc >> 24) & 0x000000ff

        # override gpio. default 0
        pad_binarray[flag_page_location + 12] = 0xff
        pad_binarray[flag_page_location + 13] = 0xff
        pad_binarray[flag_page_location + 14] = 0xff
        pad_binarray[flag_page_location + 15] = 0xff

        # override polarity. default 0
        pad_binarray[flag_page_location + 16] = 0

        # copy the reset vector stack pointer (SP) from the application binary to pad_binary
        pad_binarray[flag_page_location + 20] = app_binarray[0];
        pad_binarray[flag_page_location + 21] = app_binarray[1];
        pad_binarray[flag_page_location + 22] = app_binarray[2];
        pad_binarray[flag_page_location + 23] = app_binarray[3];

        # copy the reset vector program counter (PC) from the application binary to pad_binary
        pad_binarray[flag_page_location + 24] = app_binarray[4];
        pad_binarray[flag_page_location + 25] = app_binarray[5];
        pad_binarray[flag_page_location + 26] = app_binarray[6];
        pad_binarray[flag_page_location + 27] = app_binarray[7];
        
        # rma: boot options
        pad_binarray[flag_page_location + 28] = 0xff
        pad_binarray[flag_page_location + 29] = 0xff
        pad_binarray[flag_page_location + 30] = 0xff
        pad_binarray[flag_page_location + 31] = 0xff
        
        # rma: software version of the current image
        pad_binarray[flag_page_location + 32] = 0xff	# add me
        pad_binarray[flag_page_location + 33] = 0xff
        pad_binarray[flag_page_location + 34] = 0xff
        pad_binarray[flag_page_location + 35] = 0xff
        
        # rma: software version of the new image
        pad_binarray[flag_page_location + 36] = 0xff	#add me
        pad_binarray[flag_page_location + 37] = 0xff
        pad_binarray[flag_page_location + 38] = 0xff
        pad_binarray[flag_page_location + 39] = 0xff
        
        # rma: storage address
        pad_binarray[flag_page_location + 40] = 0xff
        pad_binarray[flag_page_location + 41] = 0xff
        pad_binarray[flag_page_location + 42] = 0xff
        pad_binarray[flag_page_location + 43] = 0xff
        
        # rma: length of new image in bytes
        pad_binarray[flag_page_location + 44] = 0xff
        pad_binarray[flag_page_location + 45] = 0xff
        pad_binarray[flag_page_location + 46] = 0xff
        pad_binarray[flag_page_location + 47] = 0xff
        
        # rma: length of new image already stored/received in bytes
        pad_binarray[flag_page_location + 48] = 0xff
        pad_binarray[flag_page_location + 49] = 0xff
        pad_binarray[flag_page_location + 50] = 0xff
        pad_binarray[flag_page_location + 51] = 0xff
        
        # rma: length of new image already stored/received in bytes
        pad_binarray[flag_page_location + 52] = 0xff
        pad_binarray[flag_page_location + 53] = 0xff
        pad_binarray[flag_page_location + 54] = 0xff
        pad_binarray[flag_page_location + 55] = 0xff


        # now output all three binary arrays in the proper order
        with open(output + '.bin', mode = 'wb') as out:
            out.write(boot_loader_binarray)
            out.write(pad_binarray)
            out.write(app_binarray)
            
    else: # OTA bin file output
        app_length = len(app_binarray)
        pad_length = 56;    #fixed pad length

        #generate mutable byte array for the boot loader
        pad_binarray = bytearray([0]*pad_length);
        
        # Insert the encryption flag (default 0)
        print("Encryption flag 0")
        pad_binarray[0]  = (0 >>  0) & 0x000000ff;
        pad_binarray[1]  = (0 >>  8) & 0x000000ff;
        pad_binarray[2]  = (0 >> 16) & 0x000000ff;
        pad_binarray[3]  = (0 >> 24) & 0x000000ff;

        # Insert the application binary load address.
        print("load_address ",hex(load_address), "(",load_address,")")
        pad_binarray[4]  = (load_address >>  0) & 0x000000ff;
        pad_binarray[5]  = (load_address >>  8) & 0x000000ff;
        pad_binarray[6]  = (load_address >> 16) & 0x000000ff;
        pad_binarray[7]  = (load_address >> 24) & 0x000000ff;
        
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

        # override gpio. default 0
        gpio = int(overridegpio)
        print("Override GPIO", hex(gpio))
        pad_binarray[16]  = (gpio >>  0) & 0x000000ff
        pad_binarray[17]  = (gpio >>  8) & 0x000000ff
        pad_binarray[18]  = (gpio >> 16) & 0x000000ff
        pad_binarray[19]  = (gpio >> 24) & 0x000000ff

        # override polarity. default 0
        print("Override Polarity", overridepolarity)
        pad_binarray[20]  = int(overridepolarity);
        pad_binarray[21]  = 0;
        pad_binarray[22]  = 0;
        pad_binarray[23]  = 0;
        
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
        
        # rma: software version of the image being transferred
        vernew = int(versionnew,16)
        print("Software version of new image", hex(vernew))
        pad_binarray[32] = (vernew >>  0) & 0x000000ff
        pad_binarray[33] = (vernew >>  8) & 0x000000ff
        pad_binarray[34] = (vernew >> 16) & 0x000000ff
        pad_binarray[35] = (vernew >> 24) & 0x000000ff
        
        # rma: transferred binary type
        btype = int(binarytype,16)
        print("Transfered binary type", hex(btype))
        pad_binarray[36] = (btype >>  0) & 0x000000ff
        pad_binarray[37] = (btype >>  8) & 0x000000ff
        pad_binarray[38] = (btype >> 16) & 0x000000ff
        pad_binarray[39] = (btype >> 24) & 0x000000ff
        
        # rma: storage type (store the image into internal or external flash)
        stype = int(storagetype,16)
        print("Transfered binary type", hex(stype))
        pad_binarray[40] = (stype >>  0) & 0x000000ff
        pad_binarray[41] = (stype >>  8) & 0x000000ff
        pad_binarray[42] = (stype >> 16) & 0x000000ff
        pad_binarray[43] = (stype >> 24) & 0x000000ff
        
        # rma: reserved word
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
                     'Combine two binary files in to a single download. Create OTA binary file.')

    parser.add_argument('--bootbin', dest='bootbin', default='../../../../apollo_evk_base/examples/multi_boot/keil/bin/multi_boot.bin',
                        help='Bootloader binary file (multi_boot.bin)')

    parser.add_argument('--appbin', dest='appbin', default='bin/exactle_fit_amota.bin',
                        help='Application binary file (app.bin)')
            
    parser.add_argument('--bintype', dest='bintype', default='boot',
                        help='Specify target output binary file type (boot/ota)')	
            
    parser.add_argument('--load-address', dest='loadaddress', default=0x4000, type = int,
                        help='Load address of the application.')	

    parser.add_argument('--override-gpio', dest='overridegpio', default='0xffffffff',
                        help = 'Override GPIO number. (Can be used to force a new image load)\n(-1 to disable)')

    parser.add_argument('--override-polarity', dest='overridepolarity', default=0, type=int,
                        help = 'Polarity for the override pin.')
	#rma: add arg options        	
    parser.add_argument('--boot-options', dest='options', default='0xffffffff',
                        help = 'Indicate the presence of an available new image.  \
                        (1 = new image in internal flash; 2 = new image in external flash; other = no new image)')            
	#rma: add arg version        	
    parser.add_argument('--version', dest='version', default='0x0',
                        help = 'Software version of the current image.')
	#rma: add arg version-new        	
    parser.add_argument('--version-new', dest='versionnew', default='0x0',
                        help = 'Software version of the new image.')                    
	#rma: add arg storage address        	
    parser.add_argument('--storage-address', dest='storageaddress', default='0xffffffff', 
                        help = 'Storage address of the new image.')
	#rma: add arg length-new        	
    parser.add_argument('--length-new', dest='lengthnew', default='0x0', 
                        help = 'Total length of the new image in bytes.')
	#rma: add arg length-stored    	
    parser.add_argument('--length-stored', dest='storedlengthnew', default='0x0', 
                        help = 'Stored length of the new image in bytes.')
	#rma: add arg crc-new    
    parser.add_argument('--crc-new', dest='crc32new', default='0x0',
                        help = 'Stored CRC value of the new image.') 

    #rma: add binary type
    parser.add_argument('--binary-type', dest='binarytype', default='0x0',
                        help = 'Binary type being transferred. (0 = image; 1 = data)') 
    
    #rma: add storage type
    parser.add_argument('--storage-type', dest='storagetype', default='0x0',
                        help = 'Storage type for image to be stored. (0 = internal; 1 = external)') 

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

    process(args.bootbin, args.appbin, args.output, args.bintype, args.loadaddress, args.overridegpio, args.overridepolarity, args.versionnew, args.binarytype, args.storagetype)

if __name__ == '__main__':
    main()
