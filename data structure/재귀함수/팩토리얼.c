#include <stdio.h>

int factorial(int n) {
	int result = 1;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

int main(void) {
	int n;
	printf("�� ���丮���� �ñ��ϳ�");
	scanf("%d", &n);
	printf("%d���丮���� ���� %d", n, factorial(n));


}