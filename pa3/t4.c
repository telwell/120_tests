#include <stdio.h>
#include "aux.h"
#include "sys.h"
#include "umix.h"

/* Tests many cars arriving from the same side. (Opposite of t3.)
 */

void Main ()
{
	InitRoad ();

	if (Fork () == 0) {
		Delay (15);			// car 2
		driveRoad (WEST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (15);			// car 3
		driveRoad (WEST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (100);			// car 4
		driveRoad (WEST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (200);			// car 5
        driveRoad (WEST, 40);
		Exit ();
	}

    Delay(10);
	driveRoad (WEST, 10);			// car 1

	Exit ();
}

