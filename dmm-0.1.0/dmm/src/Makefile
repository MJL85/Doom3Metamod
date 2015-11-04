# Minimal Makefile
#
# By: Michael Laforest <paralizer -AT- users -DOT- sourceforge -DOT- net>
#
# $Header: /cvsroot/doommod/dmm/src/Makefile,v 1.2 2005/10/25 19:29:56 paralizer Exp $

#
# Change this to your GCC 3.3 version.
#
CC = gcc-3.3.6
CCX = g++-3.3.6

#
# Where to install the package to.
# Normally you will not want to change this.
#
INSTALLPATH = ~/.doom3/.dmm
INSTALLBIN = $(INSTALLPATH)/gamex86.so

####################################################
#
# You should not need to edit below this line.
#
####################################################

#
# Universal cflags
#
CFLAGS = -Wall -pipe -m32 -fPIC

#
# Object flags
#
FLAGS = $(CFLAGS) -O2

#
# Debug object flags
#
DFLAGS = $(CFLAGS) -g

#
# Linking flags
#
LDFLAGS = -shared

#
# Target binaries (always created as BIN)
#
BIN = dmm
DBIN = dmm-debug
PDB = pdb.so

#
# Where are the DMM distributed SDK headers located?
#
DOOMSDK = ../sdk

#
# Doom3 SDK objects to link
#
LINKPATH = $(INSTALLPATH)/libs
LINK = $(LINKPATH)/d3game.so

#
# Inclusion paths.
#
INCLUDES = -I. -I../include -I../../sourcehook/ -I$(DOOMSDK)

#
# Find all source files.
#
SRC_FILES = $(wildcard *.c *.cpp)

#
# Generate a list of object files
#
OBJS = $(SRC_FILES:%.c=%.o)
OBJS := $(OBJS:%.cpp=%.o)

DOBJS = $(OBJS:%.o=d_%.o)

#
# Need this for the 'clean' target.
#
EXISTING_OBJS = $(wildcard *.o)


###############################
#
# Build targets.
#
###############################

release:
	@echo
	@echo ------
	@echo - Building DMM ...
	@echo ------
	make $(BIN)

	@echo
	@echo ------
	@echo - Building pdb ...
	@echo ------
	make $(PDB)
	
	@echo
	@echo --
	@echo -- Build complete.
	@echo --
	@echo

debug: $(DBIN)

help:
	@echo The following are valid make rules for DMM:
	@echo release - Build DMM for release.
	@echo debug   - Build DMM in debug mode.
	@echo help    - This listing.
	@echo install - Build release and copy to DMM to $(INSTALLPATH)
	@echo pdb     - Build only the pdb configuration module.
	@echo clean   - Remove all temporary build files.

#
# Create a pack file and put it in the
# directory INSTALLPATH
#
install: $(BIN) $(PDB)
	@echo
	@echo ------
	@echo - Installing DMM to $(INSTALLPATH) ...
	@echo ------
	@echo

	@echo "Checking if $(INSTALLPATH) exists ..."
	@if [ ! -d $(INSTALLPATH) ]; \
	then \
		echo "Creating $(INSTALLPATH) ..."; \
		mkdir $(INSTALLPATH) ; \
	fi

	@echo "Creating binary.conf ..."
	@echo "2" > binary.conf

	@echo "Copying binary.conf to $(INSTALLPATH) ..."
	@mv binary.conf $(INSTALLPATH)

	@echo "Copying pdb.so to $(INSTALLPATH) ..."
	@cp ../pdb/src/pdb.so $(INSTALLPATH)

	@echo "Checking for existance of $(INSTALLBIN) ..."
	@if [ -e $(INSTALLBIN) ]; \
	then \
		echo "Removing old DMM file ..."; \
		rm -f $(INSTALLBIN) ; \
	fi
	
	@echo "Copying $(BIN) to $(INSTALLBIN) ..."
	@cp $(BIN) $(INSTALLBIN)

	@echo "Setting DMM to be read only ..."
	@chmod 444 $(INSTALLBIN)
	
	@echo
	@echo ------
	@echo - Installation complete.
	@echo ------
	@echo

	@if [ ! -e $(LINK) ]; \
	then \
		echo "Note: Remember you need to copy the SDK libraries to $(LINKPATH)"; \
	fi

#
# If they exist, remove the files:
#   *.o
#   binary.conf
#   GAMEPKFILE
#
clean:
	@if [ ! -z "$(EXISTING_OBJS)" ] || [ -e $(GAMEPKFILE) ] || [ -e binary.conf ]; \
	then \
		rm *.o $(GAMEPKFILE) binary.conf &> /dev/null ; \
		echo "Cleaned files."; \
	else \
		echo "No files to clean."; \
	fi

#	cd ../pdb/ && $(MAKE) clean

$(BIN): $(OBJS)
	$(CCX) $(FLAGS) $(LDFLAGS) $(LINK) $(OBJS) -o $(BIN)

$(DBIN): $(DOBJS)
	$(CCX) $(DFLAGS) $(LDFLAGS) $(LINK) $(DOBJS) -o $(BIN)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $<

%.o: %.cpp
	$(CCX) $(FLAGS) $(INCLUDES) -c $<

d_%.o: %.c
	$(CC) $(DFLAGS) $(INCLUDES) -c $< -o $@

d_%.o: %.cpp
	$(CCX) $(DFLAGS) $(INCLUDES) -c $< -o $@

#
# Build pdb.
#
$(PDB):
	cd ../pdb/ && $(MAKE)
