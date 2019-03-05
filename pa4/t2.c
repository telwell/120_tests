#include "aux.h"
#include "umix.h"
#include "mycode4.h"

#define NUMTHREADS 7

/* Tests output of yield */

/* Tracks the yields as a comma separated list. src(->yld)->dest indicates
 * that thread src yielded to thread dest and yld was the return value of
 * the Yield call if control was exchange by an explicit yield.
 */

void Main() {
    int yld;
    void doYieldStuff();

    InitThreads();

    Printf("->%d", GetThread());

    for (int i = 1; i < NUMTHREADS; i++) {
        CreateThread(doYieldStuff, i);
    }

    Printf(",%d", GetThread());
    yld = YieldThread(GetThread());
    Printf("->%d->%d", yld, GetThread());

    Printf(",%d", GetThread());
    yld = YieldThread(1);
    Printf("->%d->%d", yld, GetThread());

    Printf(",%d", GetThread());
    ExitThread();
}

// t is this thread's id
void doYieldStuff(int t) {
    int yld;
    Printf("->%d", GetThread());

    Printf(",%d", GetThread());
    yld = YieldThread(GetThread());
    Printf("->%d->%d", yld, GetThread());

    Printf(",%d", GetThread());
    yld = YieldThread((t + 1) % NUMTHREADS);
    Printf("->%d->%d", yld, GetThread());

    Printf(",%d", GetThread());
}
