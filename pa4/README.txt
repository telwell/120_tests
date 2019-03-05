The tests in this directory can be run individually by running the commands

    gmake runt1
    ...
    gmake runtrand

You can also iterate 1000 times over the seeded random test by running

    gmake runtrandall

The results of each test except for the iterated random test are stored in
your pa4 directory as

    r<test>.txt
    myr<test>.txt

Everything can be cleaned up by running

    gmake clean

Note that all commands are using "gmake" and NOT "make" as with the previous
sets of tests. (GNU make allows for function definitions in the makefile.)
