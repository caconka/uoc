#include <stdio.h>

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
} plain;

int main(int argc, char **argv) {

	plain planeOne;
	plain planeTwo;

	printf("Enter the plane ONE id: ");
	scanf("%d", &planeOne.id);
	printf("Enter model plane %d: ", planeOne.id);
	scanf("%s", planeOne.model);
	printf("Enter year plane %d: ", planeOne.id);
	scanf("%d", &planeOne.year);
	printf("Enter plane %d utility: [COMERCIAL=0/PRIVATE=1/GOVERNMENTAL=2/MILITAR=3/EXPERIMENTAL=4/OTHERS=5] ",
			planeOne.id);
	scanf("%u", &planeOne.utility);
	printf("Enter the weight in tonnes plane %d: ", planeOne.id);
	scanf("%f", &planeOne.weight);
	printf("Enter the airplane maximum speed in km/h plane %d: ", planeOne.id);
	scanf("%f", &planeOne.maxSpeed);
	printf("Enter the airplane maximum flight height plane %d: ", planeOne.id);
	scanf("%d", &planeOne.maxHeight);
	printf("Enter the number of motors plane %d: ", planeOne.id);
	scanf("%d", &planeOne.motors);
	printf("Enter the number of seats plane %d: ", planeOne.id);
	scanf("%d", &planeOne.seats);
	printf("Enter if airplane %d is active [ACTIVE=1/INACTIVE=0]: ", planeOne.id);
	scanf(" %u", &planeOne.isActive);

	printf("===");
	printf("\nEnter the plane TWO id: ");
	scanf("%d", &planeTwo.id);
	printf("Enter model plane %d: ", planeTwo.id);
	scanf("%s", planeTwo.model);
	printf("Enter year plane %d: ", planeTwo.id);
	scanf("%d", &planeTwo.year);
	printf("Enter plane %d utility: [COMERCIAL=0/PRIVATE=1/GOVERNMENTAL=2/MILITAR=3/EXPERIMENTAL=4/OTHERS=5] ",
			planeTwo.id);
	scanf("%u", &planeTwo.utility);
	printf("Enter the weight in tonnes plane %d: ", planeTwo.id);
	scanf("%f", &planeTwo.weight);
	printf("Enter the airplane maximum speed in km/h plane %d: ", planeTwo.id);
	scanf("%f", &planeTwo.maxSpeed);
	printf("Enter the airplane maximum flight height plane %d: ", planeTwo.id);
	scanf("%d", &planeTwo.maxHeight);
	printf("Enter the number of motors plane %d: ", planeTwo.id);
	scanf("%d", &planeTwo.motors);
	printf("Enter the number of seats plane %d: ", planeTwo.id);
	scanf("%d", &planeTwo.seats);
	printf("Enter if airplane %d is active [ACTIVE=1/INACTIVE=0]: ", planeTwo.id);
	scanf(" %u", &planeTwo.isActive);
	printf("===\n");

	if (planeOne.isActive && planeOne.utility == 0 && planeTwo.isActive && planeTwo.utility == 0) {
		if (planeOne.seats >= planeTwo.seats) {
			printf("Plane ID %d", planeOne.id);
		} else {
			printf("Plane ID %d", planeTwo.id);
		}

		printf("\nTotal seats %d", planeOne.seats + planeTwo.seats);

	} else if ((planeOne.isActive == 0 || planeOne.utility != 0) &&
			(planeTwo.isActive == 0 || planeTwo.utility != 0)) {
		printf("No plane is COMMERCIAL and is ACTIVE at the same time");
		printf("\nTotal seats 0");

	} else if (planeOne.isActive && planeOne.utility == 0) {
		printf("\nTotal seats %d", planeOne.seats);

	} else {
		printf("\nTotal seats %d", planeTwo.seats);
	}

	return 0;
}
