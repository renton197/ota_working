#******************************************************************************
#
# Makefile - Rules for building the libraries, examples and docs.
#
# ${copyright}
#
# This is part of revision ${version} of the AmbiqSuite Development Package.
#
#******************************************************************************

#******************************************************************************
#
# Target directories.
#
#******************************************************************************
SUBDIRS = mcu
SUBDIRS+= boards
##### BUILD BEGIN #####
SUBDIRS+= doxygen
##### BUILD END #####
##### INTERNAL BEGIN #####
SUBDIRS+= ambiq_internal_only
##### INTERNAL END #####

HAL = $(wildcard mcu/*/hal)
BSP = $(wildcard boards/*/bsp)

#******************************************************************************
#
# Build everything.
#
#******************************************************************************
.PHONY: all
all:
	@for i in ${SUBDIRS};                                                     \
	 do                                                                       \
	     if [ -f $${i}/Makefile ];then                                        \
	         $(MAKE) -C $${i} || exit $$?;                                       \
	     fi;                                                                  \
	 done

##### BUILD BEGIN #####
#******************************************************************************
#
# Build AmbiqSuite for external consumption.
#
#******************************************************************************
LOG_DIR = build_log

ext-build: prep

checkout:
	+scripts/build/checkout.sh

style-check: checkout
	+scripts/build/style_check.sh $(LOG_DIR)

lib-brd-dox: checkout
	+scripts/build/lib_brd_dox.sh

prep: lib-brd-dox style-check
	+scripts/build/package_prep.sh

package-linux: prep
	+mv workspace AmbiqSuite ;\
	tar -cvzf AmbiqSuite.tar.gz AmbiqSuite ;\
	mv AmbiqSuite.tar.gz AmbiqSuite-`cat VERSION.build`.tar.gz ;\
	rm VERSION.build

openocd:

##### BUILD END #####
#******************************************************************************
#
# Build projects for all boards.
#
#******************************************************************************
.PHONY: boards bsp hal
boards: bsp hal
	@if [ -f boards/Makefile ];then                                           \
		 $(MAKE) -C boards || exit $$?;                                          \
	 fi;                                    

#******************************************************************************
#
# Build all BSP libraries.
#
#******************************************************************************
bsp:
	@for i in ${BSP};                                                         \
	 do                                                                       \
	     if [ -f $${i}/Makefile ];then                                        \
	         $(MAKE) -C $${i} || exit $$?;                                       \
	     fi;                                                                  \
	 done

#******************************************************************************
#
# Build the HAL.
#
#******************************************************************************
hal:
	@for i in ${HAL};                                                         \
	 do                                                                       \
	     if [ -f $${i}/Makefile ];then                                        \
	         $(MAKE) -C $${i} || exit $$?;                                       \
	     fi;                                                                  \
	 done

#******************************************************************************
#
# Build the doxygen documentation.
#
#******************************************************************************
.PHONY: doxygen
doxygen:
	$(MAKE) quick -C doxygen
##### INTERNAL BEGIN #####
#******************************************************************************
#
# Build the SVD and XML pack files.
#
#******************************************************************************
SVD = docs/app_notes/supplemental_files tools/keil_supplemental
svd:
	@for i in ${SVD} ;\
	 do \
	     if [ -f $${i}/Makefile ];then \
	         $(MAKE) -C $${i} ;\
	     fi ;\
	 done
svd-clean:
	@for i in ${SVD} ;\
	 do \
	     if [ -f $${i}/Makefile ];then \
	         $(MAKE) -C $${i} clean ;\
	     fi ;\
	 done

#******************************************************************************
#
# Copy 'common' projects into the individual boards directories.
#
#******************************************************************************
boards: projects
projects:
	@if [ -f boards/Makefile ];then                                           \
		 $(MAKE) -C boards projects|| exit $$?;                                  \
	 fi;
#******************************************************************************
#
# Make tag files for use with CTAGS compatible programs.
#
#******************************************************************************
.PHONY: tags
tags:
	@scripts/tagscripts/tag.sh
##### INTERNAL END #####

#******************************************************************************
#
# Remove build output files.
#
#******************************************************************************
clean:
	@for i in ${SUBDIRS};                                                     \
	 do                                                                       \
	     if [ -f $${i}/Makefile ];then                                        \
	         $(MAKE) -C $${i} clean;                                             \
	     fi;                                                                  \
	 done

##### INTERNAL BEGIN #####
#******************************************************************************
#
# Clean everything to its "freshly checked-out" state.
#
#******************************************************************************
.PHONY: realclean
realclean:
	@for i in ${SUBDIRS};                                                     \
	 do                                                                       \
	     if [ -f $${i}/Makefile ];then                                        \
	         $(MAKE) -C $${i} realclean;                                         \
	     fi;                                                                  \
	 done
	 rm -rf build
##### INTERNAL END #####
