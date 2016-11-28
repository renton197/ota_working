#******************************************************************************
#
# Makefile - Rules for building the libraries, examples and docs.
#
# ${copyright}
#
# This is part of revision ${version} of the AmbiqSuite Development Package.
#
#******************************************************************************

SUBDIRS=$(filter-out src/ gdb_text_files/,$(wildcard */))
##### BUILD BEGIN #####
FAMILY?=apollo2
PACKAGE?=AM_PACKAGE_BGA
BOARD?=apollo2_evk_base

BUILDPROJARGS?=-ikgs
subdirs:
	if test -f config-template.ini; then                        \
	    cp -f config-template.ini config.ini;                   \
	    sed -i 's#\$$(family)#$(FAMILY)#g' config.ini;          \
	    sed -i 's#\$$(package)#$(PACKAGE)#g' config.ini;        \
	    sed -i 's#\$$(bsp)#../../../$(BOARD)/bsp#g' config.ini; \
	fi
	../../../../scripts/buildproj/buildproj.py $(BUILDPROJARGS)
	$(MAKE) all
##### BUILD END #####
all:
	@for i in ${SUBDIRS};                       \
	 do                                         \
	     if [ -f $${i}/Makefile ]; then         \
	         $(MAKE) -C $${i} || exit $$?; fi;  \
	 done
clean:
	@for i in ${SUBDIRS};                       \
	 do                                         \
	     if [ -f $${i}/Makefile ]; then         \
	         $(MAKE) -C $${i} clean; fi;        \
	 done
##### INTERNAL BEGIN #####
realclean:
	rm -rf $(filter-out src/ gdb_text_files/,$(wildcard */)) README.txt
##### INTERNAL END #####

