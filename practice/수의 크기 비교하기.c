#include <stdio.h>

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	else
		return y;
}

int main(void) {
	int x, y;
	scanf("%d %d", &x, &y);

	int larger;
	larger = max(x, y);
	printf("�� ū ���� %d", larger);

}