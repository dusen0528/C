#include <stdio.h>

void print(int count) {
	if (count == 0) {
		return;
	}
	else {
		printf("문자열을 출력\n");
		print(count - 1);
	}
}

int main(void) {
	int number;
	printf("문자열을 몇개 출력할까요");
	scanf("%d", &number);
	print(number);

}