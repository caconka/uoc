#include <stdio.h>

typedef enum {
	COMMERCIAL, PRIVATE, GOVERNMENTAL, MILITAR, EXPERIMENTAL, OTHERS
} airplaneType;
typedef enum {FALSE, TRUE} bool;

int main() {
	int id, manufacturingYear, maxHeight, motors, seats;
	char model, actv;
	airplaneType type;
	float weight, maxSpeed;
	bool active;

	printf("Enter the airplane id: ");
	scanf("%d", &id);
	printf("Enter model: ");
	scanf(" %c", &model);
	printf("Enter manufacturing year: ");
	scanf("%d", &manufacturingYear);
	printf("Enter the weight in tonnes: ");
	scanf("%f", &weight);
	printf("Enter the airplane maximum speed in km/h: ");
	scanf("%f", &maxSpeed);
	printf("Enter the airplane maximum flight height: ");
	scanf("%d", &maxHeight);
	printf("Enter the number of motors: ");
	scanf("%d", &motors);
	printf("Enter the number of seats: ");
	scanf("%d", &seats);
	printf("Enter if airplane is active y/n: ");
	scanf(" %c", &actv);

	if (actv == 'y') {
		active = TRUE;
	} else {
		active = FALSE;
	}

	printf("\n===== Airplane id %d specifications =====\n", id);
	printf("Model: %c\n", model);
	printf("Manufacturing year: %d\n", manufacturingYear);
	printf("Weight in tonnes: %.2f, weight\n", weight);
	printf("Maximum speed in km/h: %.2f\n", maxSpeed);
	printf("Maximum flight height: %d\n", maxHeight);
	printf("Motors: %d\n", motors);
	printf("Seats: %d\n", seats);
	if (active == TRUE) {
		printf("Active: true");
	} else {
		printf("Active: false");
	}

	return 0;
}
