#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ARR_LEN 6
#define MAX_ROUNDS 10

int make_rand_num();

int main() {
	int p, b, rand_num;
	char sys_rand[ARR_LEN];
	char user_choice[ARR_LEN];	

	for (int round = 0; round <= MAX_ROUNDS; round++)
	{
		printf("Enter 4 number (ex: 1234): ");
		fgets(user_choice, ARR_LEN, stdin);
		user_choice[strlen(user_choice) - 1] = '\0';

		rand_num = make_rand_num();
		for (int i = 0; i < 4; i++) {
			sys_rand[i] = (rand_num % 10);
			rand_num /= 10;
		}
		sys_rand[strlen(sys_rand) - 1] = '\0';
		printf("Your number: %s\nSystem number: %s\n", user_choice, sys_rand);
	}
	return 0;
}

int make_rand_num()
{
	srand(time(0));
	int rand_num = rand() % 10;
	return rand_num;
}
