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
	printf("가장 큰 값은 %d입니다. %d번째 인덱스입니다", max, index+1);
	min = INT_MAX;
	for (i = 0; i < NUMBER; i++) {
		scanf("%d", &array[i]);
		if (min > array[i]) {
			min = array[i];
			index = i;
		}
	}
	printf("가장 작은 값은 %d입니다. %d번째 인덱스입니다", min, index + 1);
	return 0;
}