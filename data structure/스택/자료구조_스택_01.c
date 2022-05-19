#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

//StackType�̶�� ����ü�� int�� 100ũ���� �迭�� top��� ������ ������ ���� ����ü
typedef struct StackType {
	int arr[SIZE];
	int top;

}StackType;

//������ ���鶧���� �ʱ�ȭ�� ���ִ� �Լ�
void init(StackType* s) {
	s->top = -1; //�迭�� index�� 0���� ����
	//�����Ͱ� �ϳ� ������ ���ù迭[0] �ΰ��� [1] ... �̷� ����
}

//empty : return 1
//!empty : return 0
//������ ����ִ��� Ȯ���Ѵ�.
int is_empty(StackType* s) {
	if (s->top == -1) //������ ����Ű�� top�� -1�� ��� (���������)
		return 1;
	return 0;
}

//full : return 1
//!full : return 0
int is_full(StackType* s) {
	if (s->top == SIZE - 1) //�迭 0���� �����̴� 0~99�̹Ƿ� SIZE -1 
		return 1;
	return 0;
}

void push(StackType* s, int value) {
	if (is_full(s)) { //������ �� �������� �ȵǴ� is_full�Լ��� Ȯ�����ְ� full�Ͻ� ����
		printf("Stack is full");
		exit(1);
	}
	printf("\npush : %d\n", value);
	s->arr[++(s->top)] = value; //s�� ����Ű��  arr��[s->top�� ���� �ϳ� �������ѳ���] ������� �ִ´�.
}

int pop(StackType* s) {
	if (is_empty(s)) { //������ ��������� �����͸� �̾Ƴ� �� ������ ����ִ��� Ȯ��
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)--]; //s�� ����Ű�� arr��[s->top�� ���Ͻ����� �Ŀ�] --��
}


int peek(StackType* s) { //�� ���� �ִ� �����Ͱ� � ������ Ȯ�θ� �ϴ� �Լ�
	if (is_empty(s)) {
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)];
}

int main(void) {

	StackType s;
	init(&s); //stack �ʱ�ȭ

	push(&s, 3);
	push(&s, 2);
	push(&s, 1);

	printf("peek : %d\n", peek(&s));
	printf("pop : %d\n", pop(&s));
	printf("pop : %d\n", pop(&s));
	printf("pop : %d\n", pop(&s));
	printf("pop : %d\n", pop(&s));
}