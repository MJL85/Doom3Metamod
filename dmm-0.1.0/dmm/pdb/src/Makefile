# Minimal Makefile
#
# By: Michael Laforest <paralizer -AT- users -DOT- sourceforge -DOT- net>
#
# $Header: /cvsroot/doommod/dmm/pdb/src/Makefile,v 1.1.1.1 2005/10/20 21:36:10 paralizer Exp $

CC = gcc

# Universal cflags
CFLAGS = -Wall -pipe -m32

# Object flags
FLAGS = $(CFLAGS) -fPIC -O2

# Debug object flags
DFLAGS = $(CFLAGS) -fPIC -g

# Linking flags
LDFLAGS = -shared

# Target binaries (always created as BIN)
BIN = pdb.so
DBIN = pdb-debug.so

INCLUDES = -I. -I../include

SRC_FILES = $(wildcard *.c)

OBJS = $(SRC_FILES:%.c=%.o)
DOBJS = $(OBJS:%.o=d_%.o)

# Need this for the 'clean' target.
EXISTING_OBJS = $(wildcard *.o)

all: $(BIN)
debug: $(DBIN)

clean:
	@if [ ! -z "$(EXISTING_OBJS)" ]; \
	then \
		rm *.o ; \
		echo "Cleaned files."; \
	else \
		echo "No files to clean."; \
	fi

$(BIN): $(OBJS)
	$(CC) $(FLAGS) $(LDFLAGS) $(OBJS) -o $(BIN)

$(DBIN): $(DOBJS)
	$(CC) $(DEBUG_FLAGS) $(LDFLAGS) $(DOBJS) -o $(BIN)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $<

d_%.o: %.c
	$(CC) $(DFLAGS) $(INCLUDES) -c $< -o $@
