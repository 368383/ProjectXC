/*
 * magicianMathProblem.c
 *
 *  Created on: Jun 23, 2020
 *      Author: jonat
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int deck[54];

void intializeDeck() {
	for (int i = 1; i < 55; i++) {
		//printf("%d\n",i);
		deck[i - 1] = i;
	}
}
void removeCards() {
	printf("%s\n", "Attempting to Remove");

	for (int i = 0; i < 18; i++) {
		int random = (int) (((double) rand() / RAND_MAX) * 52);
		//printf("%d",random);
		if (deck[random] != 0) {
			deck[random] = 0;
			continue;
		}
		if (deck[random] == 0) {
			i--;
			continue;
		}
	}
}
void findCombination() {
	printf("%s\n", "Beginning to Find Set");
	while (1) {
		int trialDeck[36];
		int ansDeck[18];
		int sum = 0;
		//copy
		int size = sizeof deck / sizeof *deck;
		;
		int offSet = 0;
		for (int i = 0; i < size; i++) {
			if (deck[i] != 0) {
				trialDeck[offSet] = deck[i];
				offSet++;
			}
		}
		//printDeck(trialDeck, sizeof trialDeck);
		//finding
		int ansIndex = 0;
		for (int i = 0; i < 18; i++) {
			int random = (int) (((double) rand() / RAND_MAX) * 36);
			if (trialDeck[random] == 0) {
				i--;
				continue;
			}
			ansDeck[ansIndex] = trialDeck[random];
			ansIndex++;
			sum = sum + trialDeck[random];
		}
		if (sum == 495) {
		//	printf("SUM %d\n", sum);
			printDeck(ansDeck, sizeof ansDeck);
		//	printf("%s\n", "System Completion");
			break;
		}
	}
}
void printDeck(int sampleDeck[], int bitLength) {
	int size = (bitLength) / (sizeof *sampleDeck);

	for (int i = 0; i < size; i++) {
		printf("%d  ", sampleDeck[i]);
	}
	printf("\n");
}

//int main() {
//	time_t start;
//	time_t end;
//	start = time(NULL);
//	printf("Start Time %ld\n",start);
//
//	intializeDeck();
//	printDeck(deck, (sizeof deck));
//	printf("%s\n", "Proceeding to Remove Cards");
//	removeCards();
//	printDeck(deck, (sizeof deck));
//	findCombination();
//	end = time(NULL);
//	printf("End Time %ld\n",end);
//
//	time_t diff = start-end;
//	printf("Ellapsed Time %ld",diff);
//	return 0;
//}

