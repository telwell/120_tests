#include "aux.h"
#include "umix.h"
#include "mycode4.h"

#define NUMYIELDS	5

/* Test self yielding */

void Main()
{
	void doYieldStuff();

	InitThreads ();

    Printf("C->%d", GetThread());
	for (int i = 0; i < NUMYIELDS; i++) {
	    CreateThread(doYieldStuff, i + 1);
        Printf(",%d", GetThread());
		YieldThread(GetThread());
        Printf("->%d", GetThread());
	}
    Printf(",%d", GetThread());
    YieldThread(1);
    Printf("->%d", GetThread());

	ExitThread ();
}

void doYieldStuff(t)
	int t;				// this thread id
{
    Printf("->%d", GetThread());
	for (int i = 0; i < NUMYIELDS; i++) {
        Printf(",%d", GetThread());
		YieldThread(GetThread());
        Printf("->%d", GetThread());
	}
    Printf(",%d", GetThread());
    YieldThread((t + 1) % (NUMYIELDS + 1));
}
