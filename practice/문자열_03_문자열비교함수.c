#include <stdio.h>
#include <string.h>

int main(void) {
	char inputOne[5] = "b";
	char inputTwo[5] = "a";
	printf("문자열 비교 : %d\n", strcmp(inputOne, inputTwo));

	return 0;
}