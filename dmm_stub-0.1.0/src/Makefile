# Minimal Makefile
#
# By: Michael Laforest <paralizer -AT- users -DOT- sourceforge -DOT- net>
#
# $Header: /cvsroot/doommod/dmm_stub/src/Makefile,v 1.2 2005/10/25 19:32:01 paralizer Exp $

#
# Plugin name
#
PLUGIN = stub

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

#
# Where are the DMM distributed SDK headers located?
#
DOOMSDK = ../../dmm/sdk

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
BIN = dmm_stub
DBIN = dmm_stub-debug

#
# Doom3 SDK objects to link
#
LINKPATH = $(INSTALLPATH)/libs
LINK = $(LINKPATH)/d3game.so

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
	@echo - Building DMM [plugin: $(PLUGIN)] ...
	@echo ------
	make $(BIN)

	@echo
	@echo --
	@echo -- Build complete.
	@echo --
	@echo

debug: $(DBIN)

help:
	@echo The following are valid make rules for DMM plugins:
	@echo release - Build DMM plugin for release.
	@echo debug   - Build DMM plugin in debug mode.
	@echo help    - This listing.
	@echo install - Build release and copy to DMM plugin to $(INSTALLPATH)
	@echo clean   - Remove all temporary build files.

#
# Create a pack file and put it in the
# directory INSTALLPATH
#
install: $(BIN) $(PDB)
	@echo
	@echo ------
	@echo - Installing DMM [plugin: $(PLUGIN)] to $(INSTALLPATH) ...
	@echo ------
	@echo

	@echo "Copying $(BIN) to $(INSTALLPATH) ..."
	@if [ ! -d $(INSTALLPATH) ]; \
	then \
		mkdir $(INSTALLPATH); \
	fi
	@cp $(BIN) $(INSTALLPATH)

	@echo "Installation complete."

#
# If they exist, remove the files:
#   *.o
#
clean:
	@if [ ! -z "$(EXISTING_OBJS)" ]; \
	then \
		rm *.o &> /dev/null ; \
		echo "Cleaned files."; \
	else \
		echo "No files to clean."; \
	fi

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
