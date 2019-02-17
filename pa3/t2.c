#include <stdio.h>
#include "aux.h"
#include "sys.h"
#include "umix.h"

/* Tests cars going in opposite directions.
 */

void Main ()
{
	InitRoad ();

	if (Fork () == 0) {
		Delay (10);			// car 2
		driveRoad (WEST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (20);			// car 3
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (20);			// car 4
		driveRoad (WEST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (30);			// car 5
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (30);			// car 6
		driveRoad (WEST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (40);			// car 7
		driveRoad (EAST, 40);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (40);			// car 8
		driveRoad (WEST, 40);
		Exit ();
	}

    Delay(10);
	driveRoad (EAST, 40);			// car 1

	Exit ();
}

