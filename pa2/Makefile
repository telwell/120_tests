# Makefile to compile Umix Programming Assignment 2 (pa2)

LIBDIR = $(UMIXPUBDIR)/lib
PA2DIR = $(HOME)/pa2

CC 	= cc 
FLAGS 	= -g -L$(LIBDIR) -lumix2

TESTS = t1 t2
TESTDEPS = t1.c t2.c schedarbitrary.h schedfifo.h schedlifo.h

test:  $(TESTS)

$(PA2DIR)/mycode2arbitrary.o:	$(PA2DIR)/mycode2.c $(PA2DIR)/aux.h $(PA2DIR)/sys.h $(PA2DIR)/mycode2.h schedarbitrary.h
	cp schedarbitrary.h $(PA2DIR)
	cd $(PA2DIR) && \
	  $(CC) $(FLAGS) -o mycode2arbitrary.o -c mycode2.c -include schedarbitrary.h

$(PA2DIR)/mycode2fifo.o:	$(PA2DIR)/mycode2.c $(PA2DIR)/aux.h $(PA2DIR)/sys.h $(PA2DIR)/mycode2.h schedfifo.h
	cp schedfifo.h $(PA2DIR)
	cd $(PA2DIR) && \
	  $(CC) $(FLAGS) -o mycode2fifo.o -c mycode2.c -include schedfifo.h

$(PA2DIR)/mycode2lifo.o:	$(PA2DIR)/mycode2.c $(PA2DIR)/aux.h $(PA2DIR)/sys.h $(PA2DIR)/mycode2.h schedlifo.h
	cp schedlifo.h $(PA2DIR)
	cd $(PA2DIR) && \
	  $(CC) $(FLAGS) -o mycode2lifo.o -c mycode2.c -include schedlifo.h

t1:	t1.c $(PA2DIR)/aux.h $(PA2DIR)/umix.h $(PA2DIR)/mycode2fifo.o
	cp t1.c $(PA2DIR)
	cd $(PA2DIR) && \
	  $(CC) $(FLAGS) -o t1 t1.c mycode2fifo.o
	cd $(PA2DIR) && \
	  ./t1

t2:	t2.c $(PA2DIR)/aux.h $(PA2DIR)/umix.h $(PA2DIR)/mycode2lifo.o
	cp t2.c $(PA2DIR)
	cd $(PA2DIR) && \
	  $(CC) $(FLAGS) -o t2 t2.c mycode2lifo.o
	cd $(PA2DIR) && \
	  ./t2

clean:
	cd $(PA2DIR) && \
	  rm -f *.o $(TESTS) $(TESTDEPS)
