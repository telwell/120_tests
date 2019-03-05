#include <stdlib.h>
#include "aux.h"
#include "umix.h"
#include "mycode4.h"

// seed if none specified
#define SEED          1237

#define MAXTHREADS    10
#define ITERS_BASE    200
#define ITERS_RANGE   200
#define YIELDS_RANGE  5
#define CREATES_RANGE 5

static int rem_iters;
static int init_threads;
static int thread[MAXTHREADS];
static int num_threads;

/* Randomly tests FIFO behavior with yields
 * Note that this test is not designed to debug your code step-by-step,
 * but to do some final, broad checking that your code is correct.
 */

/* Tracks the yields as a comma separated list. src->dest indicates
 * that thread src yielded to thread dest.
 */

void extendedInitThreads() {
    rem_iters = (rand() % ITERS_RANGE) + ITERS_BASE; // 200 - 399 iterations
    init_threads = (rand() % (MAXTHREADS - 1)) + 1; // 1 - 10 initial threads
    num_threads = 1;
    thread[0] = 1;
    for (int i = 1; i < MAXTHREADS; i++) {
        thread[i] = 0;
    }
    InitThreads();
}

void extendedCreateThread() {
    void makeNewThread();
    if (num_threads < MAXTHREADS && rem_iters-- > 0) {
        thread[CreateThread(makeNewThread, 0)] = 1;
        num_threads++;
    }
}

void extendedYieldThread() {
    int t = rand() % MAXTHREADS;
    for (; t != GetThread(); t = (t + 1) % MAXTHREADS) { // yield to random thread
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

/* Takes 0 or 1 argument that defines the random seed used */

void Main(int argc, char** argv) {
    int n = SEED;
    if (argc > 1) {
        n = strtol(argv[1], 0, 10);
    }
    Printf("Initializing with seed = %d\n", n);
    srand(n);
    extendedInitThreads();

    Printf("->%d", GetThread());
    for (int i = 0; i < init_threads; i++) {
        extendedCreateThread();
    }

    extendedExitThread();
}

void makeNewThread(int t) {
    int num_yields = rand() % YIELDS_RANGE; // yield up to 10 times
    int num_try_create = (rand() % CREATES_RANGE) + 1; // try to create 1 to 5 threads
    Printf("->%d", GetThread());

    for (int i = 0; i < num_yields; i++) {
        extendedYieldThread();
    }

    for (int i = 0; i < num_try_create; i++) {
        if (num_try_create > rand() % CREATES_RANGE) { // slightly weight in favor of creating a thread
            extendedCreateThread();
        }
    }

    extendedExitThread();
}
