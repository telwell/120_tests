#include <stdio.h>
#include <assert.h>
#include "aux.h"
#include "umix.h"

// This test is modeled after...
// 1 -> 2
// 2 -> 3
// 3 -> 1
// 1 -> 2 

void Main ()
{
    int ppid, pid1, pid2, rpid;
    pid1 = 2;
    pid2 = 3;
    ppid = Getpid ();

    if ((pid1 = Fork ()) == 0) {
        /* first child executes here */
        DPrintf("Process %d about to yield to process %d\n", Getpid (), pid2); 
	rpid = Yield (pid2);
        DPrintf ("Process %d yielded to from process %d (Should be PID 1)\n", Getpid (), rpid);    
        Exit ();
    }

    if ((pid2 = Fork ()) == 0) {
        /* second child executes here */
        DPrintf("Process %d about to yield to process %d\n", Getpid (), ppid); 
	rpid = Yield (ppid);
        DPrintf ("Process %d yielded to from process %d (Should be PID 1)\n", Getpid (), rpid);    
        Exit ();
    }

    DPrintf ("Process %d about to yield to process %d\n", Getpid(), pid1);
    rpid = Yield (pid1);    // yield to second child before continuing
    DPrintf ("Process %d yielded to from process %d (Should be PID 3)\n", Getpid (), rpid);    

    DPrintf ("Process %d about to yield to process %d\n", Getpid(), pid1);
    rpid = Yield (pid1);
    DPrintf ("Process %d yielded to from process %d (Should be PID 2)\n", Getpid (), rpid);    
    // Printf ("P I am the parent, my pid is %d\n", Getpid ());
}

