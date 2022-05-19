#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) { //���� �ʱ�ȭ 
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element items) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ\n");
		return;
	}
	else s->data[++(s->top)] = items;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "������ �������");
		exit(1);
	}
	else return s->data[(s->top)--];
	
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "������ �������");
		exit(1);
	}
	else return s->data[s->top];
}
int main(void) {
	StackType fir;
	StackType sec;

	//����ü �ʱ�ȭ
	init_stack(&fir);
	init_stack(&sec);

	//fir�� 1,2,3 ������� �� �ֱ�
	push(&fir, 1);
	push(&fir, 2);
	push(&fir, 3);


	//sec�� fir���� 3,2,1 ������� �������� �ٽ� �־ 
	push(&sec, pop(&fir));
	push(&sec, pop(&fir));
	push(&sec, pop(&fir));

	//������ ���ʴ�� ������ 123
	printf("%d", pop(&sec));
	printf("%d", pop(&sec));
	printf("%d", pop(&sec));

	return 0;
}