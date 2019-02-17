#include <stdio.h>
#include "aux.h"
#include "sys.h"
#include "umix.h"

/* Tests 1 slow car blocking others from same side entering, then cars arrive
 * from the other side. Should result in alternation. (See Piazza 390)
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
		Delay (20);			// car 4
		driveRoad (WEST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (20);			// car 5
        driveRoad (WEST, 40);
		Exit ();
	}

    Delay(10);
	driveRoad (EAST, 10);			// car 1

	Exit ();
}

