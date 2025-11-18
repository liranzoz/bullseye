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
int valid_sys_rand(char arr[]);

int main() {
	srand(time(0));
	int p, b, rand_num;
	char sys_rand [5];
	char user_choice[ARR_LEN];	
	int round;
	valid_sys_rand(sys_rand);

	for (round = 1; round <= MAX_ROUNDS; round++)
	{
		printf("(Round %d/10) Enter 4 number (ex: 1234): ", round);
		fgets(user_choice, ARR_LEN, stdin);
		user_choice[strlen(user_choice) - 1] = '\0';

		p = get_p(sys_rand, user_choice);
		b = get_b(sys_rand, user_choice);
	
		if (b == 4) {
			printf("You Won!\nThe system number was: %s",sys_rand);
			break;
		}
		printf("Pgia:%d\nbool:%d\n\n", p, b);
	}
	if (b!= 4)
	{
		printf("You Lost :(\nSystem number was: %s\n\n", sys_rand);
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
	int p = 0;
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
	int b = 0;
	for (int i = 0; i < 4; i++)
	{
		if (arr1[i] == arr2[i]) {
			b++;
		}
	}
	return b;
}

int valid_sys_rand(char arr[]) {
	for (int i = 0; i < 4; i++) {
		arr[i] = make_rand_num() + '0';
	}
	arr[4] = '\0';

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i +1; j < 5; j++) {
				if (arr[i] == arr[j]) {
					arr[j] = make_rand_num() + '0';
					flag = true;
				}
			}
		}
		return 0;
	}
}
	
