#include <stdio.h>

#define MAX_PLANES 10
#define MAX_MANUFACTURER_LEN 12
#define MAX_MODEL_LEN 12

typedef enum {
	COMMERCIAL, PRIVATE, GOVERNMENTAL, MILITAR, EXPERIMENTAL, OTHERS
} tUtility;
typedef enum { FALSE, TRUE } bool;

int main(int argc, char **argv) {
	int idPlane[MAX_PLANES];
	char manufacturer[MAX_MANUFACTURER_LEN];
	char model[MAX_MODEL_LEN];
	int year[MAX_PLANES];
	int seats[MAX_PLANES];
	tUtility utility[MAX_PLANES];
	bool isActive[MAX_PLANES];
	int planes, i;
	float averageSeats = 0.0f;

	printf("Enter the number of planes: [MAX %d] ", MAX_PLANES);
	scanf("%d", &(planes));

	while (planes <= 0 || planes > MAX_PLANES) {
		printf("The number of planes is invalid, please enter a number between 1 and %d ",
				MAX_PLANES);
		scanf("%d", &planes);
	}

	printf("Enter the manufacturer: ");
	scanf("%s", manufacturer);
	printf("Enter the model: ");
	scanf("%s", model);

	for (i = 0; i < planes; i++) {
		printf("Enter plane ID: ");
		scanf("%d", &(idPlane[i]));
		printf("Enter the number of seats %d: ", idPlane[i]);
		scanf("%d", &(seats[i]));
		printf("Enter the manufacturer year of plane %d: ", idPlane[i]);
		scanf("%d", &(year[i]));
		printf("Enter plane %d utility: [COMERCIAL=0/PRIVATE=1/GOVERNMENTAL=2/MILITAR=3/EXPERIMENTAL=4/OTHERS=5] ",
				idPlane[i]);
		scanf("%u", &(utility[i]));
		printf("Is plane %d active? [false=0/true=1] ", idPlane[i]);
		scanf("%u", &(isActive[i]));
		printf("===\n");
	}

	for (i = 0; i < planes; i++) {
		averageSeats += seats[i];
	}
	averageSeats = averageSeats / planes;

	printf("\nPlanes manufacturer: %s\n", manufacturer);
	printf("Planes model: %s\n", model);
	printf("\n=== DETAILS ===\n");

	for (i = 0; i < planes; i++) {
		printf("Plane id %d\n", idPlane[i]);
		printf("Seats: %d\n", seats[i]);
		if (seats[i] >= averageSeats) {
			printf("This plane has an above or equal average seating capacity\n");
		} else {
			printf("This plane has less than average seating capacity\n");
		}
		printf("Manufacturer year: %d\n", year[i]);
		printf("Utility: %u (COMERCIAL=0/PRIVATE=1/GOVERNMENTAL=2/MILITAR=3/EXPERIMENTAL=4/OTHERS=5)\n",
				utility[i]);
		printf("Active: %u (0=false/1=true)\n", isActive[i]);
		printf("---\n");
	}

	return 0;
}
