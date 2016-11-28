#******************************************************************************
#
# Makefile - Rules for building the libraries, examples and docs.
#
# ${copyright}
#
# This is part of revision ${version} of the AmbiqSuite Development Package.
#
#******************************************************************************

SUBDIRS=$(wildcard */)

.PHONY: all clean targets
all: targets

targets:
	@for i in ${SUBDIRS};                    \
	 do                                      \
	     if [ -f $${i}/Makefile ]; then      \
	         $(MAKE) -C $${i} || exit $$?; fi;  \
	 done

clean:
	@for i in ${SUBDIRS};                    \
	 do                                      \
	     if [ -f $${i}/Makefile ]; then      \
	         $(MAKE) -C $${i} $@; fi;        \
	 done

##### INTERNAL BEGIN #####
targets: | projects

projects:
	python3 ../scripts/copyprojects/copyprojects.py

.PHONY: common
common:
	python3 ../scripts/copyprojects/copyprojects.py --common --board ${board}

realclean:
	python3 ../scripts/copyprojects/copyprojects.py --clean
	@for i in ${SUBDIRS};              \
	 do                                \
	     if [ -f $${i}/Makefile ];then \
	         $(MAKE) -C $${i} $@;  \
	     fi;                           \
	 done
##### INTERNAL END #####
