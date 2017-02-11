SRCDIR	= src
TESTSDIR= tests
OBJDIR	= obj
LIBDIR  = converter_lib
LIBSRC	= $(LIBDIR)/src
LIBINC	= $(LIBDIR)/inc
LIBOBJ	= $(LIBDIR)/obj

EXEC	= test_converter
LIB 	= roman_converter.a
LIBFLAG = -I$(LIBDIR)/inc

CFLAGS	= -Wall
INCLUDE	= -I$(TESTSDIR) -I$(LIBINC)
DEFINES	= -DLINUX
FLAGS	= $(CFLAGS) $(DEFINES) $(INCLUDE)
ADD_LIBS= -lcheck -lm -lrt -lpthread

TOBJ	= main.o
LOBJ	= converter.o

.PHONY: all clean
all:
	@echo "Target(s):   make test_converter"
	@echo "             make clean"

$(EXEC): $(OBJDIR)/$(TOBJ) $(LIBDIR)/$(LIB)
	gcc $^ -o $@ $(ADD_LIBS)

$(OBJDIR)/$(TOBJ): $(SRCDIR)/main.c
	mkdir -p $(OBJDIR)
	mkdir -p $(LIBOBJ)
	gcc $(FLAGS) -c $< -o $@

$(LIBDIR)/$(LIB): $(LIBOBJ)/$(LOBJ)
	cd $(LIBDIR)
	ar rcs $@ $^ 

$(LIBOBJ)/$(LOBJ): $(LIBSRC)/converter.c $(LIBINC)/converter.h
	cd $(LIBDIR)
	gcc -c -o $@ $< $(LIBFLAG)

clean:
	@echo "removing old library, old executable and obj directory.."
	rm -rf $(EXEC) $(OBJDIR) $(LIBOBJ) $(LIBDIR)/$(LIB)
