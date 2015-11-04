# Minimal Makefile
#
# By: Michael Laforest <paralizer -AT- users -DOT- sourceforge -DOT- net>
#
# This Makefile will invoke the Makefile in
# the src/ subdirectory.
#
# $Header: /cvsroot/doommod/dmm/Makefile,v 1.1.1.1 2005/10/20 21:36:10 paralizer Exp $

help:
	@echo The following are valid make rules for DMM:
	@echo release - Build DMM for release.
	@echo debug   - Build DMM in debug mode.
	@echo help    - This listing.
	@echo install - Build release and copy to DMM to $(INSTALLPATH)
	@echo pdb     - Build only the pdb configuration module.
	@echo clean   - Remove all temporary build files.

release:
	cd src/ && $(MAKE) release

debug:
	cd src/ && $(MAKE) debug

install:
	cd src/ && $(MAKE) install

pdb:
	cd src/ && $(MAKE) pdb

clean:
	cd src/ && $(MAKE) clean


