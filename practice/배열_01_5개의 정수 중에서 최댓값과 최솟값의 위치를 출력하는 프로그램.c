#include <stdio.h>
#define NUMBER 5
#include <limits.h>

int main(void) {

	int i, max, min, index;
	int array[NUMBER];
	max = 0;
	index = 0;
	for (i = 0; i < NUMBER; i++) {
		scanf("%d", &array[i]);
		if (max < array[i]) {
			max = array[i];
			index = i;
		}
	}
	printf("���� ū ���� %d�Դϴ�. %d��° �ε����Դϴ�", max, index+1);
	min = INT_MAX;
	for (i = 0; i < NUMBER; i++) {
		scanf("%d", &array[i]);
		if (min > array[i]) {
			min = array[i];
			index = i;
		}
	}
	printf("���� ���� ���� %d�Դϴ�. %d��° �ε����Դϴ�", min, index + 1);
	return 0;
}