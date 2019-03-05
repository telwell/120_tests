#include "aux.h"
#include "umix.h"
#include "mycode4.h"

#define INITTHREADS 3
#define NUMTHREADS 30

static int threads = 1;

/* Tests FIFO without yield */

/* Tracks the yields as a comma separated list. src->dest indicates
 * that thread src yielded to thread dest.
 */

void Main() {
    void makeNewThread();

    InitThreads();

    Printf("->%d", GetThread());
    for (int i = 0; i < INITTHREADS; i++) {
        CreateThread(makeNewThread, 0);
        threads++;
    }

    Printf(",%d", GetThread());
    ExitThread();
}

void makeNewThread(int t) {
    void makeNewThread();
    Printf("->%d", GetThread());
    if (threads < NUMTHREADS) {
        CreateThread(makeNewThread, 0);
        threads++;
    }
    Printf(",%d", GetThread());
}
