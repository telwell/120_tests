#include "aux.h"
#include "umix.h"
#include "mycode4.h"

#define INITTHREADS 5
#define WASTESIZE 400
#define DEPTH 100
#define FIRSTCHAR 'a'

static char wasters[INITTHREADS];

/* Tests if stacks get overwritten (within reasonable bounds).
 * Note that the given implementation breaks somewhere near
 * DEPTH = 100 and WASTESIZE = 550.
 */

/* Tracks the yields as a comma separated list. src->dest indicates
 * that thread src yielded to thread dest. Also tracks if any char
 * in the first stack of each thread is overwritten. bfr->aft
 * indicates that the char bfr was changed to the character aft.
 */

void recursiveSpaceWaster(int i) {
    char stuff[WASTESIZE];

    for (int j = 0; j < WASTESIZE; j++) {
        stuff[j] = wasters[GetThread()];
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
    if (i == DEPTH) {
        for (int j = 0;j < WASTESIZE; j++) {
            Printf(",(%c->%c)", wasters[GetThread()], stuff[j]);
        }
    }
}

void Main() {
    void wasteSpace();

    for (char i = 0; i < INITTHREADS; i++) {
        wasters[i] = FIRSTCHAR + i;
    }

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
