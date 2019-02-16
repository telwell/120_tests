# Makefile to test Umix Programming Assignment 3 (pa3) [updated: 1/4/18]

LIBDIR = $(UMIXPUBDIR)/lib
PA3DIR = $(HOME)/pa3

CC 	= cc 
FLAGS 	= -g -L$(LIBDIR) -lumix3

TESTS = t1
TESTDEPS = t1.c nomain.h


$(PA3DIR)/mycode3.o:	$(PA3DIR)/mycode3.c $(PA3DIR)/aux.h $(PA3DIR)/sys.h $(PA3DIR)/mycode3.h
	cd $(PA3DIR) && \
	  $(CC) $(FLAGS) -c mycode3.c

$(PA3DIR)/pa3d.o:	$(PA3DIR)/pa3d.c $(PA3DIR)/aux.h $(PA3DIR)/umix.h $(PA3DIR)/mycode3.h nomain.h
	cp nomain.h $(PA3DIR)
	cd $(PA3DIR) && \
	  $(CC) $(FLAGS) -c pa3d.c -include nomain.h

t1:	t1.c $(PA3DIR)/aux.h $(PA3DIR)/umix.h $(PA3DIR)/mycode3.o $(PA3DIR)/pa3d.o
	cp t1.c $(PA3DIR)
	cd $(PA3DIR) && \
	  $(CC) $(FLAGS) -o t1 t1.c mycode3.o pa3d.o
	cd $(PA3DIR) && \
	  ./t1

clean:
	cd $(PA3DIR) && \
	  rm -f *.o $(TESTS) $(TESTDEPS)
