#include "aux.h"
#include "umix.h"
#include "mycode4.h"

#define INITTHREADS 5
#define WASTESIZE 400
#define DEPTH 100
#define CHAR 'q'

/* Tests if stacks get overwritten (within reasonable bounds) */

/* Tracks the yields as a comma separated list. src->dest indicates
 * that thread src yielded to thread dest.
 */

void recursiveSpaceWaster(int i) {
    char stuff[WASTESIZE];

    for (int j = 0; j < WASTESIZE; j++) {
        stuff[j] = CHAR;
    }
    Printf(",%d", GetThread());
    YieldThread((GetThread() + 1) % INITTHREADS);
    Printf("->%d", GetThread());
    if (((int) &stuff[WASTESIZE-1]) - ((int) &stuff[0]) + 1 != WASTESIZE) {
        Printf ("\nStack space reservation failed\n");
        Exit ();
    }
    if (i > 0) {
        recursiveSpaceWaster(i - 1);
    }
}

void Main() {
    void wasteSpace();

    InitThreads();

    Printf("->%d", GetThread());
    for (int i = 1; i < INITTHREADS; i++) {
        CreateThread(wasteSpace, 0);
    }

    recursiveSpaceWaster(DEPTH);
    Printf(",%d", GetThread());
    ExitThread();
}

void wasteSpace(int t) {
    Printf("->%d", GetThread());
    recursiveSpaceWaster(DEPTH);
    Printf(",%d", GetThread());
    ExitThread();
}
