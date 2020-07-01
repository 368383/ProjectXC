/*
 * twentyFour.c
 *
 *  Created on: Jul 1, 2020
 *      Author: jonat
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int fieldCards[] = { 12, 4, 2, 1 };
const int answer = 24;
const char *listOfOperations[6];

void initializeOperationsMatrix() {
	listOfOperations[0] = "a+b";
	listOfOperations[1] = "a*b";
	listOfOperations[2] = "a-b";
	listOfOperations[3] = "a/b";
	listOfOperations[4] = "b/a";
	listOfOperations[5] = "b-a";
}

long mathematicalOperation(int *array) {
	int random = (int) (6 * ((double) rand() / RAND_MAX));
	int first = *array;
	int second = *(array + 1);
	printf("First and Second %d %d  Operation %s\n", first, second,
			listOfOperations[random]);

	long solution = 0;

	switch (random) {
	case 0:
		solution = (long) first + second;
		//printf("Solution %d\n ", solution);

		return solution;
	case 1:
		solution = (long) first * second;
		//printf("Solution %d\n ", solution);

		return solution;
	case 2:
		solution = (long) first - second;
		//printf("Solution %d\n ", solution);

		return solution;
	case 3:
		solution = (long) first / second;
		//	printf("Solution %d\n ", solution);

		return solution;
	case 4:
		solution = (long) second / first;
		//	printf("Solution %d\n ", solution);

		return solution;
	case 5:
		solution = (long) second - first;
		//	printf("Solution %d\n ", solution);

		return solution;
	}
	return 1000;
}
long mathematicalOperationB(long *array) {
	int random = (int) (6 * ((double) rand() / RAND_MAX));
	int first = *array;
	int second = *(array + 1);
	if ((first == 0 || second == 0) && (random == 3 || random == 4)) {
		return (long) first * second;
	}
	printf("First and Second %d %d  Operation %s\n", first, second,
			listOfOperations[random]);

	long solution = 0;

	switch (random) {
	case 0:
		solution = (long) first + second;
		//printf("Solution %d\n ", solution);

		return solution;
	case 1:
		solution = (long) first * second;
		//printf("Solution %d\n ", solution);

		return solution;
	case 2:
		solution = (long) first - second;
		//printf("Solution %d\n ", solution);

		return solution;
	case 3:
		solution = (long) first / second;
		//	printf("Solution %d\n ", solution);

		return solution;
	case 4:
		solution = (long) second / first;
		//	printf("Solution %d\n ", solution);

		return solution;
	case 5:
		solution = (long) second - first;
		//	printf("Solution %d\n ", solution);

		return solution;
	}
	return 1000;
}
int solveDouble() {
	long solution = 0;
	int i = 0;
	while (solution != answer) {
		int testCards[4];
		int firstGroup[2];
		int secondGroup[2];
		long final[2];
		memcpy(testCards, fieldCards, sizeof fieldCards);
		printArray(fieldCards, 4);
		randomAssignment(firstGroup, testCards);
		printArray(firstGroup, 2);
		randomAssignment(secondGroup, testCards);
		printArray(secondGroup, 2);
		final[0] = mathematicalOperation(firstGroup);
		printf("Final 0 %d\n", final[0]);
		final[1] = mathematicalOperation(secondGroup);
		printf("Final 1 %d\n", final[1]);
		printArray(final, 2);

		solution = mathematicalOperationB(final);
		printf("Solution %d\n ", solution);
		i++;

	}
}

void randomAssignment(int *array, int *source) {

	for (int i = 0; i < 2; i++) {
		int random = (int) (4 * ((double) rand() / RAND_MAX));
		if (source[random] != 0) {
			array[i] = source[random];
			source[random] = 0;
		} else {
			i--;
		}
	}
}

void printArray(int array[], int size) {
	for (int i = 0; i < sizeof array; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	initializeOperationsMatrix();

	if (solveDouble() == 0) {

	}
	printf("PROGRAM COMPLETION");
	double sigma = 10;

}
