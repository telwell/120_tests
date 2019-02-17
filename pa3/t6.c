#include <stdio.h>
#include "aux.h"
#include "sys.h"
#include "umix.h"

#define NBLOCK 5

/* Tests starvation. If car 1 is last, there is likely starvation, as car 1 is
 * the first car to want to go after 2. Specifically this checks if your
 * semaphores simply store/retrieve each semaphore block as the first
 * available/matching entry in a list.
 */

void Main ()
{
	InitRoad ();
    int s[NBLOCK];
    for (int i = 0; i < NBLOCK; i++) {
        s[i] = Seminit(0);
    }

	if (Fork () == 0) {
		Delay (150);			// car 2
        driveRoad (EAST, 5);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (400);			// car 3
        for (int i = 0; i < NBLOCK; i++) {
            Signal(s[i]);
        }
        Delay (200);
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
        Wait(s[0]);
		Delay (400);			// car 4
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
        Wait(s[1]);
		Delay (600);			// car 5
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
        Wait(s[2]);
		Delay (800);			// car 6
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
        Wait(s[3]);
		Delay (1000);			// car 7
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
        Wait(s[4]);
		Delay (1200);			// car 8
		driveRoad (EAST, 40);
		Exit ();
	}

    Delay(300);
	driveRoad (EAST, 40);			// car 1

	Exit ();
}

