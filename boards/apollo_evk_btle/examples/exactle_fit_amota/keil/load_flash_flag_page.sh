#!/bin/bash
# RMA: based on load_boot_image.sh from da14581_loader project.
# load_flash_flag_page.sh [none]
#
# Generate flash flag page information from project bin file and load it into 0x3C00 as the default flag page address.
# Application image link address is fixed to 0x4000.
# Override pin is fixed to GPIO 0 and polarity fixed to 0.
# Boot options/storage address/version information from flag page are not valid.
#
# == For Debug Purpose Only == 
# 1. Start an OpenOCD connection before running this program.

bfile=bin/exactle_fit_amota.bin

if [ -f "$bfile" ]; then
# Remove old flag image.
rm -f yoda_local.OTA
# generate flash flag page at 0x3c00
python copy_example_to_flash_rma.py 		-b 					"$bfile"		\
											-l 					0x4000			\
											--override-gpio 	0xffffffff 		\
											--override-polarity 0 				\
											--boot-options 		0xffffffff		\
											--version			0				\
											--version-new		0				\
											--storage-address	0xffffffff		\
											--length-new		0				\
											--length-stored		0				\
											--crc-new			0				\
											gen3C00
# load flash flag page to 0x3C00.
python copy_example_to_flash_rma.py copyto3C00
else
	echo "Error: $bfile not found."
	echo "Usage: $0 <filename>"
	exit 1
fi
