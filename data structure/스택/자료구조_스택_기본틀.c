#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}Stack;

int is_empty(Stack* s) {
	return (s->top == -1);
}

int is_full(Stack* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void init_stack(Stack* s) {
	s->top = -1;
}

void push(Stack* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택포화\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		return;
	}
	else return s->stack[(s->top)--];
}

element peek(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음");
		return;
	}
	else return s->stack[s->top];
}

int main(void) {
	Stack a;
	init_stack(&a);
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	push(&a, 4);
	printf("%d\n", pop(&a));

	printf("%d\n", pop(&a));

	printf("%d\n", pop(&a));

	printf("%d\n", pop(&a));

}