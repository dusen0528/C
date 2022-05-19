#include <stdio.h>
#include <string.h>

int main(void) {
	char input[11] = "I Love You";
	char result[5] = "Love";
	strcpy(input, result);
	printf("문자열 복사 : %s\n", input);


	return 0;
}