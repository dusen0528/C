#include <stdio.h>
#include <stdlib.h>
//�迭�� ����ִ� ������ ������ �Ųٷ� �ϴ� ���α׷��� �ۼ��غ���. ������ ����Ѵ�.

/*
���� �迭�� ũ�� : 6
������ �Է��Ͻÿ� :1 2 3 4 5 6 
������ ���� �迭 : 6 5 4 3 2 1 
*/


#define MAX_STACK_SIZE 100 

typedef struct {
	int e[MAX_STACK_SIZE];
	int top;
}stack;

void init_stack(stack* s) {
	s->top = -1;
}

int is_empty(stack* s) {
	return (s->top == -1);
}

int is_full(stack* s) {
	return(s->top == MAX_STACK_SIZE - 1);
}

void push(stack* s, int items) {
	if (is_full(s)) {
		fprintf(stderr, "������ȭ\n");
		return;
	}
	else s->e[++(s->top)] = items;
}

int pop(stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� �������");
		exit(1);
	}

	else return s->e[(s->top)--];
}

int main(void) {

	stack s; 
	init_stack(&s); //top �ʱ�ȭ
	int n;

	printf("���� �迭�� ũ�⸦ �Է��ϼ���");
	scanf("%d", &n); 

	printf("������ �Է��ϼ���\n");

	for (int i = 0; i < n; i++) {
		int a;
		scanf("\n%d", &a);
		push(&s, a);
	}
	printf("������ ���� �迭: \n");

	for (int i = 0; i < n; i++) {
		printf("---%d---\n", pop(&s));

	}

}