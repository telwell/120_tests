The tests in this directory can be run individually by running the commands

    make t1
    make t2

Note that the scheduling policy must be manually set before running each
test by editing mycode2.c. Each test will warn you if you have the policy
schedule set to the wrong value. t1 requires the FIFO policy and t2
requires the LIFO policy. This manual editing before each test can be
skipped by making two permanent modifications to mycode2.c. These
modifications should not change how your code functions, but be sure to
save or know how to undo these changes before making them.

First, add the following 3 lines between the include statements and the
definition of TIMERINTERVAL:

    #ifndef SCHEDPOLICY
    #define SCHEDPOLICY ARBITRARY	// set policy here
    #endif

The first few lines of the file should look something like this:

    #include "aux.h"
    #include "sys.h"
    #include "mycode2.h"

    #ifndef SCHEDPOLICY
    #define SCHEDPOLICY ARBITRARY	// set policy here
    #endif

    #define TIMERINTERVAL 100000	// in ticks (tick = 10 msec)

Second, replace the

    SetSchedPolicy (ARBITRARY);		// set policy here

statement with

    SetSchedPolicy (SCHEDPOLICY);

in the InitSched function. Your code should look something like this:

    /* First, set the scheduling policy. You should only set it
     * from within this conditional statement.  While you are working
       ...
     * the condition will be false and SetSchedPolicy (p) will not be
     * called, thus leaving the policy to whatever we chose to test. 
     */
    if (GetSchedPolicy () == NOSCHEDPOLICY) {	// leave as is
        SetSchedPolicy (SCHEDPOLICY);
    }

Make sure your code still compiles.

Now, the only difference in your code is that to manually set the
scheduling policy for pa2a-b-c, you must change the value after

    #define SCHEDPOLICY ...	// set policy here

instead of the parameter of

    SetSchedPolicy (...);

For instance,

    #define SCHEDPOLICY ARBITRARY	// set policy here

sets the policy to arbitrary whereas

    #define SCHEDPOLICY LIFO	// set policy here

sets the policy to LIFO.

Additionally, all of the tests can now be run without manually changing
the scheduling policy. You can also run all of the tests at once
by running

    make test

The pa2 directory can then be cleaned up from this directory by running

    make clean

