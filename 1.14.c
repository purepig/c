#include<stdio.h>

#define WORD_LENGTH 15

int main() {

	int character, varray[WORD_LENGTH] = { 0 }, i, count, max, temp, visited, barray[WORD_LENGTH] = { 0 }, farray[WORD_LENGTH] = { 0 }, fqncy, found;

	i = count = found = max = fqncy = temp = visited = 0;

	while ((character = getchar()) != EOF) {
		if (character != ' ' && character != '\n' && character != '\t') {
			++count;
		}
		else {
			if (count != 0) {
				varray[i] = count;
				i++;
				count = 0;
			}
		}
	}

	//Prints the length of each word
	for (i = 0;i < WORD_LENGTH;i++) {
		printf("%d ", varray[i]);
	}

	printf("\n");

	/*
	 * This block of code calculates the frequency of each element from one array
	 * and sets it in corresponding location in another array.
	 *
	 * For ex: 5 is at 0th index and it's frequency is 3
	 * so 3 is set at 0th index in another array.
	 */
	for (int i = 0;i < WORD_LENGTH;i++) {
		temp = i;
		while (temp >= 0) {
			if (varray[i] == varray[--temp]) {
				visited = 1;
				break;
			}
		}

		if (visited == 0) {
			for (int j = 0;j < WORD_LENGTH;j++) {
				if (varray[i] == varray[j]) {
					++fqncy;
				}
			}
		}

		if (visited == 0) {
			barray[i] = fqncy;
			fqncy = 0;
		}
		visited = 0;
	}

	//Prints the frequency of each word
	for (i = 0;i < WORD_LENGTH;i++) {
		printf("%d ", barray[i]);
	}

	printf("\n");

	/*
	 * This block of code calculates the frequency of each element from one array
	 * and sets it in corresponding location in another array.
	 *
	 * For ex: 5 is at 0th index and it's frequency is 3
	 * so 3 is set at 0th index in another array.
	 */
	for (int i = 0;i < WORD_LENGTH;i++) {
		temp = i;
		while (temp >= 0) {
			if (barray[i] == barray[--temp]) {
				visited = 1;
				break;
			}
		}

		if (visited == 0) {
			for (int j = 0;j < WORD_LENGTH;j++) {
				if (barray[i] == barray[j]) {
					++fqncy;
				}
			}
		}

		if (visited == 0) {
			farray[i] = fqncy;
			fqncy = 0;
		}
		visited = 0;
	}

	//Prints the frequency of each word
	for (i = 0;i < WORD_LENGTH;i++) {
		printf("%d ", farray[i]);
	}



	//Finds the maximum frequency which will be on Y-axis
	for (i = 0;i < WORD_LENGTH;i++) {
		if (farray[i] > max) {
			max = farray[i];
		}
	}

	printf("\n---------------VERTICAL HISTOGRAM STARTS--------------------\n");



	for (i = max;i > 0;i--) {
		printf("%d", i);

		for (int j = 1;j <= 11;j++) {
			found = 1;
			for (int k = 0;k < WORD_LENGTH;k++) {
				if (j == barray[k] && j < 11) {
					if (farray[k] == i) {
						printf(" X ");
						--farray[k];
						found = 0;
					}
				}
				else if (j > 10 && farray[k] == i) {
					printf("   X");
					found = 0;
				}
			}
			if (found == 1) {
				printf("   ");
			}
		}
		printf("\n\n");
	}

	printf(" ");

	for (i = 1;i <= 11;i++) {
		if (i == 11) {
			printf(">10");
		}
		else {
			printf(" %d ", i);
		}
	}
	printf("\n---------------VERTICAL HISTOGRAM ENDS--------------------\n");


	return 0;
}