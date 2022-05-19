#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct { //�������� ������ ������ �ִ� element ����ü�� ������
	int student_no;
	char name[MAX_STACK_SIZE];
	char address[MAX_STRING];
}element;

element stack[MAX_STACK_SIZE]; //�� ����ü�� �迭�� 100
int top = -1;

int is_empty() {
	return (top == -1);
}

int is_full() {
	return (top == MAX_STACK_SIZE - 1);
}

void push(element item) {
	if (is_full()) {
		fprintf(stderr, "������ ���� á���ϴ�.");
		return;
	}
	else stack[++top] = item; 
}

element pop() {
	if (is_empty()) {
		fprintf(stderr, "������ ��� �ֽ��ϴ�.");
		exit(1);
	}
	else return stack[top--];
}


int main(void) {
	element ie = { //ie��� ����ü�� ������ �Է�
		20190001,
		"Hong",
		"Ulsan"
	};
	element oe; //���ο� oe��� ����ü ����

	push(ie); //ie ����ü�� ���� ���ÿ� �־��ְ�
	oe = pop(); //pop�Լ��� ���� ���� oe�� �־��ش�

	printf("%d %s %s", oe.student_no, oe.name, oe.address); //oe�� ������ �� ������ ����� ���ؼ� Ȯ��
	return 0;
}