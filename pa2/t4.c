#include <stdio.h>
#include "aux.h"
#include "umix.h"

void Main ()
{
    if (Fork () == 0) {

        if (Fork () == 0) {

            if (Fork () == 0) {

                if (Fork () == 0) {
                    RequestCPUrate (5);                    // process 5
                    SlowPrintf (5, "55555555555555555555");
                    Exit ();
                }

                RequestCPUrate (5);                        // process 4
                SlowPrintf (5, "44444444444444444444");
                Exit ();
            }

            RequestCPUrate (10);                            // process 3
            SlowPrintf (5, "33333333333333333333");
            Exit ();
        }

        RequestCPUrate (30);                                // process 2
        SlowPrintf (5, "22222222222222222222");
        Exit ();
    }

    RequestCPUrate (50);                                    // process 1
    SlowPrintf (5, "11111111111111111111");
    Exit ();
}
