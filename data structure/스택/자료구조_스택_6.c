#include <stdio.h>
#include <stdlib.h>
//배열에 들어있는 정수의 순서를 거꾸로 하는 프로그램을 작성해보자. 스택을 사용한다.

/*
정수 배열의 크기 : 6
정수를 입력하시오 :1 2 3 4 5 6 
반전된 정수 배열 : 6 5 4 3 2 1 
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
		fprintf(stderr, "스택포화\n");
		return;
	}
	else s->e[++(s->top)] = items;
}

int pop(stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 비어있음");
		exit(1);
	}

	else return s->e[(s->top)--];
}

int main(void) {

	stack s; 
	init_stack(&s); //top 초기화
	int n;

	printf("정수 배열의 크기를 입력하세요");
	scanf("%d", &n); 

	printf("정수를 입력하세요\n");

	for (int i = 0; i < n; i++) {
		int a;
		scanf("\n%d", &a);
		push(&s, a);
	}
	printf("반전된 정수 배열: \n");

	for (int i = 0; i < n; i++) {
		printf("---%d---\n", pop(&s));

	}

}