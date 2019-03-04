# Makefile to test Umix Programming Assignment 4 (pa4) [updated: 3/4/19]

LIBDIR = $(UMIXPUBDIR)/lib
PA4DIR = $(HOME)/pa4

CC 	= cc 
FLAGS 	= -g -L$(LIBDIR) -lumix4

TESTS = t1 myt1 t2 myt2 t3 myt3 t4 myt4 t5 myt5 t6 myt6 t7 myt7 t8 myt8 t9 myt9 trand
TESTDEPS = t1.c t2.c t3.c t4.c t5.c t6.c t7.c t8.c t9.c usemythread.h

$(PA4DIR)/usemythread.h:	usemythread.h
	cp usemythread.h $(PA4DIR)

$(PA4DIR)/mycode4.o:	$(PA4DIR)/mycode4.c $(PA4DIR)/aux.h $(PA4DIR)/umix.h $(PA4DIR)/mycode4.h
	cd $(PA4DIR) && \
	  $(CC) $(FLAGS) -c mycode4.c

clean:
	cd $(PA4DIR) && \
	  rm -f *.o $(TESTS) $(TESTDEPS)
