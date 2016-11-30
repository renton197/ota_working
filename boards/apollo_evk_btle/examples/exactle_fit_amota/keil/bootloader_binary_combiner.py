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
def process(boot_loader_filename, app_filename,  output):

    # Open the file, and read it into an array of integers.
    with open(boot_loader_filename, mode = 'rb') as f_bl:
        boot_loader_binarray = f_bl.read()
        f_bl.close()

    # Open the file, and read it into an array of integers.
    with open(app_filename, mode = 'rb') as f_app:
        app_binarray = f_app.read()
        f_app.close()

    boot_length = len(boot_loader_binarray)
    print("boot size ",boot_length)
    if boot_length > 16383:
	    print("ERROR boot loader image is too big");
	    return

    app_length  = len(app_binarray)

    pad_length  = 0x4000 - len(boot_loader_binarray)

    # this is where we will write the application size in FLASH
    flag_page_location = 0x3c00 - len(boot_loader_binarray)

    print("pad_length ",pad_length);

    #generate mutable byte array for the boot loader
    pad_binarray = bytearray([0]*pad_length);

    # Insert the application binary load address.
    #print("load_address ",hex(load_address), "(",load_address,")")
    pad_binarray[flag_page_location + 0]  = 0x00;
    pad_binarray[flag_page_location + 1]  = 0x40;
    pad_binarray[flag_page_location + 2]  = 0x00;
    pad_binarray[flag_page_location + 3]  = 0x00;

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
	
    # # rma: software version of the current image
    # pad_binarray[flag_page_location + 32] = 0xff
    # pad_binarray[flag_page_location + 33] = 0xff
    # pad_binarray[flag_page_location + 34] = 0xff
    # pad_binarray[flag_page_location + 35] = 0xff
	
    # # rma: software version of the current image
    # pad_binarray[flag_page_location + 36] = 0xff
    # pad_binarray[flag_page_location + 37] = 0xff
    # pad_binarray[flag_page_location + 38] = 0xff
    # pad_binarray[flag_page_location + 39] = 0xff
	
    # # rma: storage address
    # pad_binarray[flag_page_location + 40] = 0xff
    # pad_binarray[flag_page_location + 41] = 0xff
    # pad_binarray[flag_page_location + 42] = 0xff
    # pad_binarray[flag_page_location + 43] = 0xff
	
	# # rma: length of new image in bytes
    # pad_binarray[flag_page_location + 44] = 0xff
    # pad_binarray[flag_page_location + 45] = 0xff
    # pad_binarray[flag_page_location + 46] = 0xff
    # pad_binarray[flag_page_location + 47] = 0xff
	
	# # rma: length of new image already stored/received in bytes
    # pad_binarray[flag_page_location + 48] = 0xff
    # pad_binarray[flag_page_location + 49] = 0xff
    # pad_binarray[flag_page_location + 50] = 0xff
    # pad_binarray[flag_page_location + 51] = 0xff
	
	# # rma: length of new image already stored/received in bytes
    # pad_binarray[flag_page_location + 52] = 0xff
    # pad_binarray[flag_page_location + 53] = 0xff
    # pad_binarray[flag_page_location + 54] = 0xff
    # pad_binarray[flag_page_location + 55] = 0xff


    # now output all three binary arrays in the proper order
    with open(output + '.bin', mode = 'wb') as out:
        out.write(boot_loader_binarray)
        out.write(pad_binarray)
        out.write(app_binarray)

def parse_arguments():
    parser = argparse.ArgumentParser(description =
                     'Combine two binary files in to a single download.')

    parser.add_argument('--bootbin', dest='bootbin', default='../../../../apollo_evk_base/examples/multi_boot/keil/bin/multi_boot.bin',
                        help='Bootloader binary file (multi_boot.bin)')

    parser.add_argument('--appbin', dest='appbin', default='bin/exactle_fit_amota.bin',
                        help='Application binary file (app.bin)')

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

    process(args.bootbin, args.appbin, args.output)

if __name__ == '__main__':
    main()
