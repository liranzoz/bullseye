#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ARR_LEN 6
#define MAX_ROUNDS 10

int make_rand_num();
int get_p(char arr1[], char arr2[]);
int get_b(char arr1[], char arr2[]);

int main() {
	srand(time(0));
	int p, b, rand_num;
	char sys_rand [5];
	char user_choice[ARR_LEN];	

	for (int i = 0; i < 4; i++) {
				rand_num = make_rand_num();
				sys_rand[i] = rand_num + '0';
			}
	sys_rand[4] = '\0';


	for (int round = 0; round <= MAX_ROUNDS; round++)
	{
		printf("Enter 4 number (ex: 1234): ");
		fgets(user_choice, ARR_LEN, stdin);
		user_choice[strlen(user_choice) - 1] = '\0';

		printf("Your number: %s\nSystem number: %s\n\n", user_choice, sys_rand);
	}
	return 0;
}

int make_rand_num()
{
	int rand_num = rand() % 10;
	return rand_num;
}

int get_p(char arr1[], char arr2[])
{
	int p;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			if (i != j && arr1[i] == arr2[j])
			{
				p++;
			}
		}
	}
	return p;
}

int get_b(char arr1[], char arr2[])
{
	int b;
	for (int i = 0; i < 4; i++)
	{
		if (arr1[i] == arr2[i]) {
			b++;
		}
	}
	return b;
}
