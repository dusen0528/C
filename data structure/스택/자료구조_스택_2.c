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
	if (is_full()) { //만약 is_full함수가 즉 top == (MAX_STACK_SIZE -1)이 참이라면 스택이 가득 찼다는 것을 알려주는 조건
		fprintf(stderr, "스택이 가득 찼습니다.");
		return;
	}
	else stack[++top] = item; //아니라면 stack[top배열 +1]의 값에 item을 넣는다
	
}


element pop() { 
	if (is_empty()) { //top == -1 일 경우에는 스택이 비어있다는 것을 알려줌
		fprintf(stderr, "스택이 비어있습니다");
		exit(1);
	}
	else return stack[top--]; //그게 아니라면 stack[top]을 출력하고 stack[top-1]을 리턴함
}

element peek() {
	if (is_empty()) { //top == -1 일 경우에는 스택이 비어있다는 것을 알려줌
		fprintf(stderr, "스택이 비어있습니다");
		exit(1);
	}
	else return stack[top]; //스택의 값을 건드리는 것이 아닌 가장 위에 있는 top을 보기만 하는 함수이다.
}


int main(void) {
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());

	printf("%d\n", pop());

	printf("%d\n", pop());
}