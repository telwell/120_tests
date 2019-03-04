#include <stdio.h>
#include <stdlib.h>
#include "aux.h"
#include "sys.h"
#include "umix.h"

#define SEED 1237

/* Tests starvation. If car 1 is last, there is likely starvation, as car 1 is
 * the first car to want to go after 2. Specifically this checks if your
 * semaphores simply store/retrieve each semaphore block as the first
 * available/matching entry in a list.
 */

void Main (int argc, char** argv)
{
	int n = SEED;
    int num_cars;
    InitRoad();

    if (argc > 1) {
        n = strtol(argv[1], 0, 10);
    }

    srand(n);
    num_cars = rand() % MAXPROCS;

    DPrintf("Seed: %d, Num Cars: %d\n", n, num_cars);

    for (int i = 0; i < num_cars; i++) {
        int delay = rand() % 3000;
        int speed = (rand() % 30) + 30;
        int direction = (rand() % 2 == 0) ? EAST : WEST;
	    if (i < num_cars - 1) {
            if (Fork () == 0) {
                DPrintf("Car %d generated travelling %s with delay %d and speed %d\n", i + 2, (direction == EAST) ? "east" : "west", delay, speed);
		        Delay (delay);			// car i + 1
                driveRoad (direction, speed);
		        Exit ();
	        }
        } else {
            DPrintf("Car %d generated travelling %s with delay %d and speed %d\n", 1, (direction == EAST) ? "east" : "west", delay, speed);
            Delay(delay);
	        driveRoad (direction, speed);			// car 1
	        Exit ();
        }
    }
}

