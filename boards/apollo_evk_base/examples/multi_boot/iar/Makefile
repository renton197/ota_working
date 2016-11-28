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
K := $(shell type -p IarBuild.exe)

ifeq ($(K),)
all clean:
	$(info IAR tools not found, skipping...)
else
all:
	IarBuild.exe multi_boot.ewp -make Debug -log info

clean:
	@+echo Cleaning... ;\
	IarBuild.exe multi_boot.ewp -clean Debug -log all
endif
