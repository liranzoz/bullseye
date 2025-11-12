#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int make_rand_num();

int main() {
	int rand_num = make_rand_num();

	return 0;
}

int make_rand_num()
{
	srand(time(0));
	int rand_num = rand() % 10;
	return rand_num;
}
