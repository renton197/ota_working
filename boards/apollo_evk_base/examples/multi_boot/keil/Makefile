#******************************************************************************
#
# Makefile - Rules for building the libraries, examples and docs.
#
# ${copyright}
# 
# This is part of revision ${version} of the AmbiqSuite Development Package.
#
#******************************************************************************

SHELL=/bin/bash
K := $(shell type -p uv4)

ifeq ($(K),)
all clean:
	$(info Keil tools not found, skipping...)
else
all:
	+mkdir -p bin ;\
	(uv4 -b -t "multi_boot" multi_boot.uvprojx -j0) || \
	    ( RC=$$?;[ $$RC -eq 1 ] || exit $$RC )
clean:
	@+echo Cleaning... ;\
	rm -rf bin
endif

