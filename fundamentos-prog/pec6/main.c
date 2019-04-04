#include <stdio.h>
#include <string.h>

#define MAX_MODEL_LEN 12

typedef enum {
	COMMERCIAL, PRIVATE, GOVERNMENTAL, MILITAR, EXPERIMENTAL, OTHERS
} tUtility;

typedef enum { FALSE, TRUE } bool;

typedef struct {
	int id;
	char model[MAX_MODEL_LEN];
	int year;
	tUtility utility;
	float weight;
	float maxSpeed;
	int maxHeight;
	int motors;
	int seats;
	bool isActive;
} tPlane;

tPlane planeRead() {
	tPlane p;

	printf("Identifier for plane (integer): >>");
	scanf("%d", &p.id);
	printf("Number of seats for plane %d (integer): >>", p.id);
	scanf("%d", &p.seats);
	printf("Enter if plane %d is active [ACTIVE=1/INACTIVE=0]: ", p.id);
	scanf(" %u", &p.isActive);
	printf("Model for plane %d: >>", p.id);
	scanf("%s", p.model);
	printf("Year for plane %d: >>", p.id);
	scanf("%d", &p.year);
	printf("Utility for plane %d: [COMERCIAL=0/PRIVATE=1/GOVERNMENTAL=2/MILITAR=3/EXPERIMENTAL=4/OTHERS=5] ",
			p.id);
	scanf("%u", &p.utility);
	printf("Weight in tonnes for plane %d: >>", p.id);
	scanf("%f", &p.weight);
	printf("Max speed in km/h for plane %d: ", p.id);
	scanf("%f", &p.maxSpeed);
	printf("Max height for plane %d: ", p.id);
	scanf("%d", &p.maxHeight);
	printf("Number of motors for plane %d: ", p.id);
	scanf("%d", &p.motors);

	return p;
}

char * readUtility(int u) {
	switch (u) {
		case 0: return "COMERCIAL";
		case 1: return "PRIVATE";
		case 2: return "GOVERNMENTAL";
		case 3: return "MILITAR";
		case 4: return "EXPERIMENTAL";
		default: return "OTHERS";
	}
}

char * readBoolean(int b) {
	if (b) {
		return "true";
	}
	return "false";
}

void planeWrite(tPlane p) {
	printf("Plane ID: %d", p.id);
	printf("\nPlane MODEL: %s", p.model);
	printf("\nPlane YEAR: %d", p.year);
	printf("\nPlane UTILITY: %s", readUtility(p.utility));
	printf("\nPlane WEIGHT: %.2f", p.weight);
	printf("\nPlane MAX_SPEED: %.2f", p.maxSpeed);
	printf("\nPlane MAX_HEIGHT: %d", p.maxHeight);
	printf("\nPlane MOTORS: %d", p.motors);
	printf("\nPlane SEATS: %d", p.seats);
	printf("\nPlane ACTIVE: %s", readBoolean(p.isActive));
}

tPlane planeCopy(tPlane p) {
	tPlane pCopy;

	pCopy.id = p.id;
	strcpy(pCopy.model, p.model);
	pCopy.year = p.year;
	pCopy.utility = p.utility;
	pCopy.weight = p.weight;
	pCopy.maxSpeed = p.maxSpeed;
	pCopy.maxHeight = p.maxHeight;
	pCopy.motors = p.motors;
	pCopy.seats = p.seats;
	pCopy.isActive = p.isActive;

	return pCopy;
}

int planeAnalise(tPlane p1, tPlane p2) {
	int result = 1;

	if (p1.maxSpeed == p2.maxSpeed) {
		if (p1.maxHeight == p2.maxHeight) {
			result = 0;
		} else if (p1.maxHeight < p2.maxHeight) {
			result = 2;
		}
	} else if (p1.maxSpeed < p2.maxSpeed) {
		result = 2;
	}

	return result;
}

void copyAndWrite(tPlane p) {
	tPlane plane3 = planeCopy(p);
	planeWrite(plane3);
}

int main(int argc, char **argv) {

	tPlane plane1;
	tPlane plane2;

	printf("=== ENTER PLANE 1 ===\n");
	plane1 = planeRead();
	printf("\n === ENTER PLANE 2 ===\n");
	plane2 = planeRead();

	if (plane1.utility != 3 && plane2.utility != 3) {
		printf("\nNeither of two planes are military");

	} else if (plane1.utility == 3 && plane2.utility == 3) {
		switch (planeAnalise(plane1, plane2)) {
			case 1:
				planeWrite(plane1);
				break;
			case 2:
				planeWrite(plane2);
				break;
			default:
				printf("\nTwo planes have identical characteristics of speed and height");
		}

	} else if (plane1.utility == 3) {
		printf("\nPlane 1 is MILITAR\n");
		copyAndWrite(plane1);

	} else {
		printf("\nPlane 2 is MILITAR\n");
		copyAndWrite(plane2);
	}

	return 0;
}
