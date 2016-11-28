#******************************************************************************
#
# Makefile - Rules for building the libraries, examples and docs.
#
# ${copyright}
#
# This is part of revision ${version} of the AmbiqSuite Development Package.
#
#******************************************************************************

# Force BSP build first.
SUBDIRS:=$(wildcard bsp*/) $(filter-out bsp%/,$(wildcard */))

all:
	@for i in ${SUBDIRS}; do \
	    if [ -f $${i}/Makefile ]; then \
	         $(MAKE) -C $${i} || exit $$? ;\
	    fi ;\
	done
clean:
	@for i in ${SUBDIRS}; do \
	    if [ -f $${i}/Makefile ]; then \
	         $(MAKE) -C $${i} $@ || exit $$? ;\
	    fi ;\
	done

##### INTERNAL BEGIN #####
realclean:
	@for i in ${SUBDIRS}; do \
	    if [ -f $${i}/Makefile ]; then \
	         $(MAKE) -C $${i} $@ || exit $$? ;\
	    fi ;\
	done
##### INTERNAL END #####	 
