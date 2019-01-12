# Makefile to test Umix Programming Assignment 1 (pa1) [updated: 1/4/18]

LIBDIR = $(UMIXPUBDIR)/lib
PA1DIR = $(HOME)/pa1

CC 	= cc 
FLAGS 	= -g -L$(LIBDIR) -lumix1

TEST =	test_1 test_2 test_1.c test_2.c

$(PA1DIR)/mycode1.o:	$(PA1DIR)/mycode1.c $(PA1DIR)/aux.h $(PA1DIR)/sys.h $(PA1DIR)/mycode1.h
	cd $(PA1DIR) && \
	  $(CC) $(FLAGS) -c mycode1.c

test:	test_1.c test_2.c $(PA1DIR)/aux.h $(PA1DIR)/umix.h $(PA1DIR)/mycode1.o
	cp test_1.c test_2.c $(PA1DIR)
	cd $(PA1DIR) && \
	  $(CC) $(FLAGS) -o test_1 test_1.c mycode1.o && \
	  $(CC) $(FLAGS) -o test_2 test_2.c mycode1.o
	cd $(PA1DIR) && \
	  ./test_1 && \
	  ./test_2

clean:
	cd $(PA1DIR) && \
	  rm -f *.o $(TEST)
