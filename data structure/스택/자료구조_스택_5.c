#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int* data; //data를 포인터로 선언
	int capacity; //현재 크기
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1; 
	s->capacity = 1;
	s->data = (int*)malloc(s->capacity * sizeof(int)); //동적 할당
}

void del(StackType* s) {
	free(s); //동적할당 해제
}

int is_empty(StackType* s) {
	return (s->top == -1); 
}

int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

void push(StackType* s, int item) {
	if (is_full(s)) { //현재 스택이 포화상태라면
		s->capacity *= 2; 
		s->data = (int*)realloc(s->data, s->capacity * sizeof(int)); //할당받은 메모리를 유지하면서 배열의 크기를 2배 늘려서 재할당 받는다.
	}
	s->data[++(s->top)] = item; //data++[top]에다가 item을 대입
	
}

int pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main(void) {
	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));

	printf("%d\n", pop(&s));

	printf("%d\n", pop(&s));
	del(s.data);

}