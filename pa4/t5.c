#include "aux.h"
#include "umix.h"
#include "mycode4.h"

#define INITTHREADS 5
#define MAXTHREADS 10
#define BASESTEP 3
#define MAXITERS 50

static int thread[MAXTHREADS];
static int num_threads;
static int num_iters;

/* Tests FIFO with yield */

/* Tracks the yields as a comma separated list. src->dest indicates
 * that thread src yielded to thread dest.
 */

void extendedInitThreads() {
    num_threads = 1;
    thread[0] = 1;
    for (int i = 1; i < MAXTHREADS; i++) {
        thread[i] = 0;
    }
    InitThreads();
}

void extendedCreateThread() {
    void makeNewThread();
    if (num_threads < MAXTHREADS && num_iters++ < MAXITERS) {
        thread[CreateThread(makeNewThread, 0)] = 1;
        num_threads++;
    }
}

void extendedYieldThread() {
    int t = (GetThread() + BASESTEP) % MAXTHREADS;
    for (; t != GetThread(); t = (t + 1) % MAXTHREADS) {
        if (thread[t]) {
            break;
        }
    }
    Printf(",%d", GetThread());
    YieldThread(t);
    Printf("->%d", GetThread());
}

void extendedExitThread() {
    thread[GetThread()] = 0;
    num_threads--;
    Printf(",%d", GetThread());
    ExitThread();
}

void Main() {
    extendedInitThreads();

    Printf("->%d", GetThread());
    for (int i = 0; i < INITTHREADS; i++) {
        extendedCreateThread();
    }

    extendedYieldThread();
    extendedExitThread();
}

void makeNewThread(int t) {
    Printf("->%d", GetThread());
    extendedCreateThread();

    extendedYieldThread();
    extendedExitThread();
}
