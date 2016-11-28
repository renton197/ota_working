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
## @bug Iar does not buld this example.
BUILDPROJARGS?=-kgs
subdirs:
	../../../../scripts/buildproj/buildproj.py $(BUILDPROJARGS)
	$(MAKE) all
##### BUILD END #####
all:
	@for i in ${SUBDIRS};                    \
	 do                                      \
	     if [ -f $${i}/Makefile ]; then      \
	         $(MAKE) -C $${i} || exit $$?; fi;  \
	 done
clean:
	@for i in ${SUBDIRS};                    \
	 do                                      \
	     if [ -f $${i}/Makefile ]; then      \
	         $(MAKE) -C $${i} clean; fi;        \
	 done
##### INTERNAL BEGIN #####
realclean:
	rm -rf $(filter-out $(SRCDIRS),$(wildcard */)) README.txt
##### INTERNAL END #####

