#******************************************************************************
#
# Makefile - Rules for building the libraries, examples and docs.
#
# ${copyright}
# 
# This is part of revision ${version} of the AmbiqSuite Development Package.
#
#******************************************************************************

SRCDIRS=src/ gdb_text_files/
SUBDIRS=$(filter-out $(SRCDIRS),$(wildcard */))

##### BUILD BEGIN #####
BUILDPROJARGS?=-ikgs
subdirs:
	../../../scripts/buildproj/buildproj.py $(BUILDPROJARGS)
	$(MAKE) all
##### BUILD END #####
all: am_bsp_gpio.h
	@for i in $(SUBDIRS);                    \
	 do                                      \
	     if [ -f $${i}/Makefile ]; then      \
	         $(MAKE) -C $${i} || exit $$?; fi;  \
	 done
#### BUILD BEGIN ####
bp: am_bsp_gpio.h

BSP_DEPS = apollo-pinout.csv
BSP_DEPS+= ../../../scripts/pinconfig_gen/bsp_gen.py
BSP_DEPS+= ../../../scripts/pinconfig_gen/am_bsp_gpio_template.c
BSP_DEPS+= ../../../scripts/pinconfig_gen/am_bsp_gpio_template.h

am_bsp_gpio.h: $(BSP_DEPS)
	python3 ../../../scripts/pinconfig_gen/bsp_gen.py \
		apollo-pinout.csv

#### BUILD END ####
clean:
	@for i in $(SUBDIRS);                    \
	 do                                      \
	     if [ -f $${i}/Makefile ]; then      \
	         $(MAKE) -C $${i} clean; fi;        \
	 done
##### INTERNAL BEGIN #####
realclean:
	rm -rf $(filter-out $(SRCDIRS),$(wildcard */)) README.txt am_bsp_gpio.h
##### INTERNAL END #####

