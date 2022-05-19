#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

//StackType이라는 구조체는 int형 100크기의 배열과 top라는 정수형 변수를 가진 구조체
typedef struct StackType {
	int arr[SIZE];
	int top;

}StackType;

//스택을 만들때마다 초기화를 해주는 함수
void init(StackType* s) {
	s->top = -1; //배열은 index의 0부터 시작
	//데이터가 하나 있으면 스택배열[0] 두개면 [1] ... 이런 형식
}

//empty : return 1
//!empty : return 0
//스택이 비어있는지 확인한다.
int is_empty(StackType* s) {
	if (s->top == -1) //스택이 가리키는 top이 -1일 경우 (비어있을때)
		return 1;
	return 0;
}

//full : return 1
//!full : return 0
int is_full(StackType* s) {
	if (s->top == SIZE - 1) //배열 0부터 시작이니 0~99이므로 SIZE -1 
		return 1;
	return 0;
}

void push(StackType* s, int value) {
	if (is_full(s)) { //스택이 꽉 차있으면 안되니 is_full함수로 확인해주고 full일시 종료
		printf("Stack is full");
		exit(1);
	}
	printf("\npush : %d\n", value);
	s->arr[++(s->top)] = value; //s가 가리키는  arr에[s->top를 먼저 하나 증가시켜놓고] 밸류값을 넣는다.
}

int pop(StackType* s) {
	if (is_empty(s)) { //스택이 비어있으면 데이터를 뽑아낼 수 없으니 비어있는지 확인
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)--]; //s가 가리키는 arr에[s->top을 리턴시켜준 후에] --됨
}


int peek(StackType* s) { //맨 위에 있는 데이터가 어떤 것인지 확인만 하는 함수
	if (is_empty(s)) {
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)];
}

int main(void) {

	StackType s;
	init(&s); //stack 초기화

	push(&s, 3);
	push(&s, 2);
	push(&s, 1);

	printf("peek : %d\n", peek(&s));
	printf("pop : %d\n", pop(&s));
	printf("pop : %d\n", pop(&s));
	printf("pop : %d\n", pop(&s));
	printf("pop : %d\n", pop(&s));
}