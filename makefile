# Modified for C++
# Makefile for CMSC435 Project 1 (Fall 2009)
# Author: Aaron Curtis (acurti1@umbc.edu)
# To use Pixie, you must first set the appropriate
# environment variables:
#  source /afs/umbc.edu/users/r/h/rheingan/pub/435/pixie-csh

SOURCE = test.cpp
IMAGE = hobby.tif
OBJECTS = $(SOURCE:.cpp=.o)
RIBS = $(IMAGE:.tif=.rib)
PROGRAM = $(IMAGE:.tif=.gen)

RENDER = $(PIXIEHOME)/bin/rndr

# flags for compiling
CXX = /usr/bin/g++
CXXFLAGS = -Wno-write-strings -I$(PIXIEHOME)/include  -g
LDFLAGS = -L$(PIXIEHOME)/lib -g
LDLIBS = -lpixiecommon -lri -lsdr -lm

# tell make to automatically figure out things with these suffixes
.SUFFIXES: .tif .rib .gen

# tell make not to automatically delete things
.PRECIOUS: $(RIBS) $(PROGRAM) $(OBJECTS)

# make dependency: dummy target "all" depends on all of the images
# so "make all" will make all images. Also, since this is the first
# target in the file, just "make" is the same as "make all"

all: $(IMAGE)

# .tif from .rib
%.tif: %.rib
	$(RENDER) $<

# .rib from program
%.rib: %.gen
	./$<

# program from .o
$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) $(LDFLAGS) $(LDLIBS)

# .o from .c 
%.o: %.c
	$(CXX) -c $(CXXFLAGS) $<

# delete program, object files, and annoying xemacs ~ files
clean:
	rm -f *~ *.o *.gen core.*

# also delete images and ribs
clobber: clean
	rm -f *.rib *.tif

update:
	convert ri.tif pic.jpg
	mv pic.jpg /afs/umbc.edu/users/d/v/dvan3/home/www/
