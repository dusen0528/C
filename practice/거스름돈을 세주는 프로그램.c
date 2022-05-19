/*#include <stdio.h>

int main() {
	int price, manun, ochnun, chunun;

	printf("금액을 입력하세요 : ");
	scanf("%d", &price);
	manun = price / 10000;
	ochnun = (price - manun * 10000) / 5000;
	chunun = (price - manun * 10000 - ochnun * 5000) / 1000;
	printf("거스름돈은\n만원짜리 %d장\n오천원짜리 %장\n천원짜리 %장 입니다.", manun, ochnun, chunun);

}*/

//함수를 이용한 표현 

#include <stdio.h>

int smallest(int number)
{
	int count = 0;
	while (number >= 50000) {
		number -= 50000;
		count++;
	}
	while (number >= 10000) {
		number -= 10000;
		count++;
	}
	while (number >= 5000) {
		number -= 5000;
		count++;
	}
	while (number >= 1000) {
		number -= 1000;
		count++;
	}
	while (number >= 500) {
		number -= 500;
		count++;
	}
	while (number >= 100) {
		number -= 100;
		count++;
	}
	while (number >= 50) {
		number -= 50;
		count++;
	}
	while (number >= 10) {
		number -= 10;
		count++;
	}

	return count;
}


int main(void) {
	int number;
	printf("금액을 입력하세요 : ");
	scanf("%d", &number);
	printf("최소 화폐 개수는 %d 입니다\n.", smallest(number));

	return 0;
}