#include <stdio.h>
#include "aux.h"
#include "umix.h"

/*
* You can use:
*   #undef MAXPROCS
*   #define MAXPROCS X
* in mycode.c to redefine MAXPROCS to X in order to test how you
* handle too many processes trying to get scheduled.
*
* The following tests are in the format:
* # MAXPROCS : <EXPECTED OUTPUT>
* e.g. 2 : 11111111112222222222
* means that when you redefine MAXPROCS to 2 you should see the 
* corresponding output.
*
* FIFO:
*       10 : 11111111112222222222333333333344444444445555555555
*       3  : 1111111111222222222233333333335555555555
*       2  : 111111111122222222225555555555 
*
* LIFO:
*       10 : 55555555552222222222333333333344444444441111111111
*       3  : 55555555552222222222333333333344444444441111111111
*       2  : 2222222222333333333344444444441111111111 
* 
* Can you see why when MAXPROCS is 3 FIFO needs to skip a process
* but LIFO does not? Does LIFO w/ MAXPROCS at 2 make sense?
*/

void Main ()
{
    if (Fork () == 0) {
        if (Fork () == 0) {
            SlowPrintf (5, "5555555555");		// process 5
            Exit ();
        }
        SlowPrintf (5, "2222222222");			// process 2
        Exit ();
    }
    if (Fork () == 0) {
        SlowPrintf (5, "3333333333");			// process 3
        Exit ();
    }
    if (Fork () == 0) {
        SlowPrintf (5, "4444444444");			// process 4
        Exit ();
    }
    SlowPrintf (5, "1111111111");			// process 1
    Exit ();
}
