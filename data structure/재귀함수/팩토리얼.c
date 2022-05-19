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
	printf("몇 팩토리얼이 궁금하냐");
	scanf("%d", &n);
	printf("%d팩토리얼의 값은 %d", n, factorial(n));


}