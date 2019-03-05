# Makefile to test Umix Programming Assignment 4 (pa4) [updated: 3/4/19]

LIBDIR = $(UMIXPUBDIR)/lib
PA4DIR = $(HOME)/pa4

CC 	= cc 
FLAGS 	= -g -L$(LIBDIR) -lumix4

TESTS = t1 myt1 t2 myt2 t3 myt3 t4 myt4 t5 myt5 t6 myt6 t7 myt7 t8 myt8 t9 myt9 trand
TESTDEPS = t1.c t2.c t3.c t4.c t5.c t6.c t7.c t8.c t9.c usemythread.h

define test_source_template
$(PA4DIR)/t$(1).c: t$(1).c
	cp t$(1).c $(PA4DIR)
endef

define test_exe_template
$(PA4DIR)/t$(1): $(PA4DIR)/t$(1).c $(PA4DIR)/aux.h $(PA4DIR)/umix.h $(PA4DIR)/mycode4.o
	cd $(PA4DIR) && \
	  $(CC) $(FLAGS) -o t$(1) t$(1).c mycode4.o
endef

define test_myexe_template
$(PA4DIR)/myt$(1): $(PA4DIR)/t$(1).c $(PA4DIR)/aux.h $(PA4DIR)/umix.h $(PA4DIR)/mycode4.o $(PA4DIR)/usemythread.h
	cd $(PA4DIR) && \
	  $(CC) $(FLAGS) -o myt$(1) t$(1).c mycode4.o -include usemythread.h
endef

define test_run_template
runt$(1): $(PA4DIR)/t$(1) $(PA4DIR)/myt$(1)
	cd $(PA4DIR) && \
	  ./t$(1) && \
	  ./myt$(1)
endef

add_test = \
	$(eval $(call test_source_template,$1)) \
	$(eval $(call test_exe_template,$1)) \
	$(eval $(call test_myexe_template,$1)) \
	$(eval $(call test_run_template,$1))

$(PA4DIR)/usemythread.h:	usemythread.h
	cp usemythread.h $(PA4DIR)

$(PA4DIR)/mycode4.o:	$(PA4DIR)/mycode4.c $(PA4DIR)/aux.h $(PA4DIR)/umix.h $(PA4DIR)/mycode4.h
	cd $(PA4DIR) && \
	  $(CC) $(FLAGS) -c mycode4.c

clean:
	cd $(PA4DIR) && \
	  rm -f *.o $(TESTS) $(TESTDEPS)

$(call add_test,1)

