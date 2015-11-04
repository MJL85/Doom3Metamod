# Minimal Makefile
#
# By: Michael Laforest <paralizer -AT- users -DOT- sourceforge -DOT- net>
#
# This Makefile will invoke the Makefile in
# the src/ subdirectory.
#
# $Header: /cvsroot/doommod/dmm/pdb/Makefile,v 1.1.1.1 2005/10/20 21:36:10 paralizer Exp $

BIN = pdb
DBIN = pdb-debug

all: $(BIN)
debug: $(DBIN)

$(BIN):
	cd src/ && $(MAKE)

$(DBIN):
	cd src/ && $(MAKE) debug

clean:
	cd src/ && $(MAKE) clean
