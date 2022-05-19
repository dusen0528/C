#include <stdio.h>

void print() {
	printf("Hello World!!\n");
}

int add(int x, int y) {
	return	x + y;
}

int main(void) {

	print();
	int num1 = 10;
	int num2 = 20;
	
	int result = add(num1, num2);
	printf("%d", result);

	return 0;
}