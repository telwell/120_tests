#include <stdio.h>
#include <assert.h>
#include "aux.h"
#include "umix.h"

// TRY: different orders of yielding to test.

void Main ()
{
        int pid = 0, rpid;

        if ((pid = Fork ()) == 0) {
                assert(pid == 0);
                Exit ();
        }
        
        assert(pid > 0);
        rpid = Yield (pid);     // yield to first child before continuing
        assert(rpid == 2);

        if ((pid = Fork ()) == 0) {
                assert(pid == 0);
                Exit ();
        }
        assert(pid > 0);

        rpid = Yield (pid);     // yield to second child before continuing
        assert(rpid == 3);
        DPrintf("Congrats! All of these tests have passed.");
}

