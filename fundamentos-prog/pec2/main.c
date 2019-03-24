/*
 * File: main.c
 * Author: Carlos Cabezas
 * Date: 09-03-2019
 * Description: PEC2 Fundamentos de programación
*/

#include <stdio.h>

typedef enum {
	COMMERCIAL, PRIVATE, GOVERNMENTAL, MILITAR, EXPERIMENTAL, OTHERS
} tUtility;
typedef enum { FALSE, TRUE } bool;

int main(int argc, char **argv)
{
	const float WEIGHT_EMPTY1 = 41415.0;
	const float MAX_WEIGHT_WITHOUT_GAS1 = 64689.0;
	const short NUM_PASSENGERS_PER_FLIGHT_ATTENDANT = 50;
	const float AVERAGE_WEIGHT = 95.0;
	tUtility utility1, utility2, utility3;
	short year1, year2, year3;
	short seats1, seats2, seats3;
	bool isActive1, isActive2, isActive3;
	short passengers1, passengers2, passengers3;
	short cabinGroup1;
	float weight1, maxLoad1;
	bool privatePlane = FALSE;
	bool sameYear = FALSE;
	bool sameStatus = FALSE;

	utility1 = COMMERCIAL;
	seats1 = 200;

	printf("Enter manufacturing year plane 1: ");
	scanf("%hu", &year1);
	printf("Enter manufacturing year plane 2: ");
	scanf("%hu", &year2);
	printf("Enter manufacturing year plane 3: ");
	scanf("%hu", &year3);
	printf("Enter plane 2 utility: [COMERCIAL=0/PRIVATE=1/GOVERNMENTAL=2/MILITAR=4/EXPERIMENTAL=5/OTHERS=6] ");
	scanf("%u", &utility2);
	printf("Enter plane 3 utility: [COMERCIAL=0/PRIVATE=1/GOVERNMENTAL=2/MILITAR=4/EXPERIMENTAL=5/OTHERS=6] ");
	scanf("%u", &utility3);
	printf("Enter the number of seats for plane 2: ");
	scanf("%hu", &seats2);
	printf("Enter the number of seats for plane 3: ");
	scanf("%hu", &seats3);
	printf("Is plane 1 active? [false=0/true=1] ");
	scanf("%u", &isActive1);
	printf("Is plane 2 active? [false=0/true=1] ");
	scanf("%u", &isActive2);
	printf("Is plane 3 active? [false=0/true=1] ");
	scanf("%u", &isActive3);

	printf("Number of passengers of plane 1: [1-%d] ", seats1);
	scanf("%hu", &passengers1);
	if (passengers1 < 0) {
		passengers1 = 1;
	} else if (passengers1 > seats1) {
		passengers1 = seats1;
	}

	printf("Number of passengers of plane 2: [1-%d] ", seats2);
	scanf("%hu", &passengers2);
	if (passengers2 < 0) {
		passengers2 = 1;
	} else if (passengers1 > seats2) {
		passengers2 = seats2;
	}

	printf("Number of passengers of plane 3: [1-%d] ", seats3);
	scanf("%hu", &passengers3);
	if (passengers3 < 0) {
		passengers3 = 1;
	} else if (passengers1 > seats3) {
		passengers3 = seats3;
	}

	cabinGroup1 = 3 + (passengers1 - 1) / NUM_PASSENGERS_PER_FLIGHT_ATTENDANT;

	weight1 = (float)(cabinGroup1 + passengers1) * AVERAGE_WEIGHT;
	maxLoad1 = MAX_WEIGHT_WITHOUT_GAS1 - WEIGHT_EMPTY1 - weight1;

	if ((utility1 == PRIVATE && seats1 >= 15) || (utility2 == PRIVATE && seats2 >= 15)
			|| (utility3 == PRIVATE && seats3 >= 15)) {
		privatePlane = TRUE;
	}

	if (year1 == year2 && year1 == year3) {
		sameYear = TRUE;
	}

	if (isActive1 == isActive2 && isActive2 == isActive3) {
		sameStatus = TRUE;
	}

	printf("\nMax load plane 1: %.2f Kg\n", maxLoad1);
	printf("Have the same status? %u (0=false/1=true)\n", sameStatus);
	printf("Were manufactured in the same year? %u (0=false/1=true)\n", sameYear);
	printf("Is there any plane with more than 15 passengers? %u (0=false/1=true)\n",
			privatePlane);

	return 0;
}
