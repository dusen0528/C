#include <stdio.h> 

//���� ����
int hour;
int minute;
int minuteAdd;

void counter() {
	minute += minuteAdd;
	hour += minute / 60;
	minute %= 60;
	hour %= 24;
}


int main(void) {
	printf("�ø� �Է��ϼ��� : \n");
	scanf("%d", &hour);
	printf("���� �Է��ϼ��� : \n");
	scanf("%d", &minute);
	printf("���� ���� �Է��ϼ��� : \n");
	scanf("%d", &minuteAdd);
	counter();
	printf("������ �ð��� %d�� %d�� �Դϴ�\n", hour, minute) ;

}