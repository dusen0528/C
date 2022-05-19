#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) { //스택 초기화 
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
		fprintf(stderr, "스택 포화\n");
		return;
	}
	else s->data[++(s->top)] = items;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음");
		exit(1);
	}
	else return s->data[(s->top)--];
	
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음");
		exit(1);
	}
	else return s->data[s->top];
}
int main(void) {
	StackType fir;
	StackType sec;

	//구조체 초기화
	init_stack(&fir);
	init_stack(&sec);

	//fir에 1,2,3 순서대로 값 넣기
	push(&fir, 1);
	push(&fir, 2);
	push(&fir, 3);


	//sec에 fir에서 3,2,1 순서대로 꺼낸것을 다시 넣어서 
	push(&sec, pop(&fir));
	push(&sec, pop(&fir));
	push(&sec, pop(&fir));

	//위에서 차례대로 꺼내면 123
	printf("%d", pop(&sec));
	printf("%d", pop(&sec));
	printf("%d", pop(&sec));

	return 0;
}