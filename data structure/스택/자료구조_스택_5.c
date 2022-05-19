#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int* data; //data�� �����ͷ� ����
	int capacity; //���� ũ��
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1; 
	s->capacity = 1;
	s->data = (int*)malloc(s->capacity * sizeof(int)); //���� �Ҵ�
}

void del(StackType* s) {
	free(s); //�����Ҵ� ����
}

int is_empty(StackType* s) {
	return (s->top == -1); 
}

int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

void push(StackType* s, int item) {
	if (is_full(s)) { //���� ������ ��ȭ���¶��
		s->capacity *= 2; 
		s->data = (int*)realloc(s->data, s->capacity * sizeof(int)); //�Ҵ���� �޸𸮸� �����ϸ鼭 �迭�� ũ�⸦ 2�� �÷��� ���Ҵ� �޴´�.
	}
	s->data[++(s->top)] = item; //data++[top]���ٰ� item�� ����
	
}

int pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
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