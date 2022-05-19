#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct { //여러가지 변수를 가지고 있는 element 구조체를 선언함
	int student_no;
	char name[MAX_STACK_SIZE];
	char address[MAX_STRING];
}element;

element stack[MAX_STACK_SIZE]; //그 구조체의 배열은 100
int top = -1;

int is_empty() {
	return (top == -1);
}

int is_full() {
	return (top == MAX_STACK_SIZE - 1);
}

void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택이 가득 찼습니다.");
		return;
	}
	else stack[++top] = item; 
}

element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택이 비어 있습니다.");
		exit(1);
	}
	else return stack[top--];
}


int main(void) {
	element ie = { //ie라는 구조체의 값들을 입력
		20190001,
		"Hong",
		"Ulsan"
	};
	element oe; //새로운 oe라는 구조체 선언

	push(ie); //ie 구조체의 값을 스택에 넣어주고
	oe = pop(); //pop함수로 꺼낸 값을 oe에 넣어준다

	printf("%d %s %s", oe.student_no, oe.name, oe.address); //oe의 값들이 잘 들어갔는지 출력을 통해서 확인
	return 0;
}