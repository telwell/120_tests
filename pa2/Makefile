# Makefile to compile Umix Programming Assignment 2 (pa2)

LIBDIR = $(UMIXPUBDIR)/lib
# LIBDIR = $(UMIXROOTDIR)/sys

CC 	= cc 
FLAGS 	= -g -L$(LIBDIR) -lumix2

PA2 =	pa2a pa2b pa2c
TESTS = t1

pa2:	$(PA2)
test:  $(TESTS)

t1:	t1.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o t1 t1.c mycode2.o

pa2a:	pa2a.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o pa2a pa2a.c mycode2.o

pa2b:	pa2b.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o pa2b pa2b.c mycode2.o

pa2c:	pa2c.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o pa2c pa2c.c mycode2.o

mycode2.o:	mycode2.c aux.h sys.h mycode2.h
	$(CC) $(FLAGS) -c mycode2.c

clean:
	rm -f *.o $(PA2) $(TESTS)
