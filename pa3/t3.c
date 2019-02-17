#include <stdio.h>
#include "aux.h"
#include "sys.h"
#include "umix.h"

/* Tests many cars arriving from the same side.
 */

void Main ()
{
	InitRoad ();

	if (Fork () == 0) {
		Delay (15);			// car 2
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (15);			// car 3
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (100);			// car 4
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (200);			// car 5
        driveRoad (EAST, 40);
		Exit ();
	}

    Delay(10);
	driveRoad (EAST, 10);			// car 1

	Exit ();
}

