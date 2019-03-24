/*
 * File: main.c
 * Author: Carlos Cabezas
 * Date: 15-03-2019
 * Description: PEC3 Fundamentos de programación
*/

#include <stdio.h>

#define NUM_SEATS_FIRST 16
#define NUM_SEATS_BUSINESS 20
#define NUM_SEATS_ECONOMY 144
#define PITCH_FIRST 135
#define PITCH_BUSINESS 100
#define PITCH_ECONOMY 74
#define LENGTH_FIRST 600
#define LENGTH_BUSINESS 550
#define SEATS_ECONOMY_ROW 6
#define SEATS_BUSINESS_ROW 4

int main(int argc, char **argv)
{
	int averageSales[3];
	int seatsEconomy;
	int seatsBusiness;

	printf("Enter the average sales of the FIRST CLASS: ");
	scanf("%d", &(averageSales[0]));
	printf("Enter the average sales of the BUSINESS CLASS: ");
	scanf("%d", &(averageSales[1]));
	printf("Enter the average sales of the ECONOMY CLASS: ");
	scanf("%d", &(averageSales[2]));

	if (averageSales[0] < 0 || averageSales[0] > NUM_SEATS_FIRST ||
			averageSales[1] < 0 || averageSales[1] > NUM_SEATS_BUSINESS ||
			averageSales[2] < 0 || averageSales[2] > NUM_SEATS_ECONOMY) {
		printf("ERROR");
		return 0;
	}

	if (averageSales[0] < NUM_SEATS_FIRST / 4) {
		if (averageSales[1] < NUM_SEATS_BUSINESS / 2) {
			seatsEconomy = ((LENGTH_FIRST + LENGTH_BUSINESS) / PITCH_ECONOMY) * SEATS_ECONOMY_ROW;
			printf("It is recommended to convert the entire plane to a single class, ECONOMY.\
					 Number of economy seats to be added: %d", seatsEconomy);
		} else {
			seatsBusiness = (LENGTH_FIRST / PITCH_BUSINESS) * SEATS_BUSINESS_ROW;
			printf("It is recommended to convert the FIRST class to BUSINESS class.\
					 Number of business seats to be added: %d", seatsBusiness);
		}
	} else {
		printf("It is necessary to make a more detailed study");
	}

	return 0;
}
