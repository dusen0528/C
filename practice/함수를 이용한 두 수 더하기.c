#include <stdio.h>

int get_integer() {
	int a;
	printf("���� �Է��ϼ��� : ");
	scanf("%d", &a);
	return a;
}

int add(int x, int y) {
	return x + y;
}


int main(void) {
	int x = get_integer();
	int y = get_integer();
	int sum = add(x, y);
	printf("%d", sum);
}
