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
subdirs: am_hal_pin.h
	../../../scripts/buildproj/buildproj.py $(BUILDPROJARGS)
	$(MAKE) all

am_hal_pin.h: apollo-pinout.csv ../../../scripts/pinconfig_gen/pin_header_template.h
	python3 ../../../scripts/pinconfig_gen/pinconfig_gen.py apollo-pinout.csv \
	../../../scripts/pinconfig_gen/pin_header_template.h -o am_hal_pin.h

##### BUILD END #####
all:
	@for i in ${SUBDIRS};                    \
	 do                                      \
	     if [ -f $${i}/Makefile ]; then      \
	         $(MAKE) -C $${i} || exit $$?; fi;  \
	 done
##### INTERNAL BEGIN #####
BUILDPROJARGS?=-ikgs
all: am_hal_pin.h
##### INTERNAL END#####
clean:
	@for i in ${SUBDIRS};                    \
	 do                                      \
	     if [ -f $${i}/Makefile ]; then      \
	         $(MAKE) -C $${i} clean; fi;        \
	 done
##### INTERNAL BEGIN #####
realclean:
	rm -rf $(filter-out $(SRCDIRS),$(wildcard */)) README.txt am_hal_pin.h
##### INTERNAL END #####

