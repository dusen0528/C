#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
	return (top == -1); 
}

int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) { 
	if (is_full()) { //���� is_full�Լ��� �� top == (MAX_STACK_SIZE -1)�� ���̶�� ������ ���� á�ٴ� ���� �˷��ִ� ����
		fprintf(stderr, "������ ���� á���ϴ�.");
		return;
	}
	else stack[++top] = item; //�ƴ϶�� stack[top�迭 +1]�� ���� item�� �ִ´�
	
}


element pop() { 
	if (is_empty()) { //top == -1 �� ��쿡�� ������ ����ִٴ� ���� �˷���
		fprintf(stderr, "������ ����ֽ��ϴ�");
		exit(1);
	}
	else return stack[top--]; //�װ� �ƴ϶�� stack[top]�� ����ϰ� stack[top-1]�� ������
}

element peek() {
	if (is_empty()) { //top == -1 �� ��쿡�� ������ ����ִٴ� ���� �˷���
		fprintf(stderr, "������ ����ֽ��ϴ�");
		exit(1);
	}
	else return stack[top]; //������ ���� �ǵ帮�� ���� �ƴ� ���� ���� �ִ� top�� ���⸸ �ϴ� �Լ��̴�.
}


int main(void) {
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());

	printf("%d\n", pop());

	printf("%d\n", pop());
}