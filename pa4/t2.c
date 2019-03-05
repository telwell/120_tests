#include "aux.h"
#include "umix.h"
#include "mycode4.h"

#define NUMYIELDS	5

/* Test self yielding */

/* Tracks the yields as a comma separated list. src->dest indicates
 * that thread src yielded to thread dest.
 */

void Main() {
    void doYieldStuff();

    InitThreads ();

    Printf("->%d", GetThread());
    for (int i = 0; i < NUMYIELDS; i++) {
        CreateThread(doYieldStuff, i + 1);
        Printf(",%d", GetThread());
        YieldThread(GetThread());
        Printf("->%d", GetThread());
    }
    Printf(",%d", GetThread());
    YieldThread(1);
    Printf("->%d", GetThread());

    ExitThread();
}

// t is this thread's id
void doYieldStuff(int t) {
    Printf("->%d", GetThread());
	for (int i = 0; i < NUMYIELDS; i++) {
        Printf(",%d", GetThread());
		YieldThread(GetThread());
        Printf("->%d", GetThread());
	}
    Printf(",%d", GetThread());
    YieldThread((t + 1) % (NUMYIELDS + 1));
}
