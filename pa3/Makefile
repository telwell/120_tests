# Makefile to test Umix Programming Assignment 3 (pa3) [updated: 1/4/18]

LIBDIR = $(UMIXPUBDIR)/lib
PA3DIR = $(HOME)/pa3

CC 	= cc 
FLAGS 	= -g -L$(LIBDIR) -lumix3

TESTS = t1 t2 t3 t4 t5 t6 t7 t8 t9
TESTDEPS = t1.c t2.c t3.c t4.c t5.c t6.c t7.c t8.c t9.c nomain.h


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

t2:	t2.c $(PA3DIR)/aux.h $(PA3DIR)/umix.h $(PA3DIR)/mycode3.o $(PA3DIR)/pa3d.o
	cp t2.c $(PA3DIR)
	cd $(PA3DIR) && \
	  $(CC) $(FLAGS) -o t2 t2.c mycode3.o pa3d.o
	cd $(PA3DIR) && \
	  ./t2

t3:	t3.c $(PA3DIR)/aux.h $(PA3DIR)/umix.h $(PA3DIR)/mycode3.o $(PA3DIR)/pa3d.o
	cp t3.c $(PA3DIR)
	cd $(PA3DIR) && \
	  $(CC) $(FLAGS) -o t3 t3.c mycode3.o pa3d.o
	cd $(PA3DIR) && \
	  ./t3

t4:	t4.c $(PA3DIR)/aux.h $(PA3DIR)/umix.h $(PA3DIR)/mycode3.o $(PA3DIR)/pa3d.o
	cp t4.c $(PA3DIR)
	cd $(PA3DIR) && \
	  $(CC) $(FLAGS) -o t4 t4.c mycode3.o pa3d.o
	cd $(PA3DIR) && \
	  ./t4

t5:	t5.c $(PA3DIR)/aux.h $(PA3DIR)/umix.h $(PA3DIR)/mycode3.o $(PA3DIR)/pa3d.o
	cp t5.c $(PA3DIR)
	cd $(PA3DIR) && \
	  $(CC) $(FLAGS) -o t5 t5.c mycode3.o pa3d.o
	cd $(PA3DIR) && \
	  ./t5

t6:	t6.c $(PA3DIR)/aux.h $(PA3DIR)/umix.h $(PA3DIR)/mycode3.o $(PA3DIR)/pa3d.o
	cp t6.c $(PA3DIR)
	cd $(PA3DIR) && \
	  $(CC) $(FLAGS) -o t6 t6.c mycode3.o pa3d.o
	cd $(PA3DIR) && \
	  ./t6

clean:
	cd $(PA3DIR) && \
	  rm -f *.o $(TESTS) $(TESTDEPS)
