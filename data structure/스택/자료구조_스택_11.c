#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100

typedef struct Stacktype {
	char stack[MAX_SIZE];
	int top;
}Stacktype;

void Stack_init(Stacktype* s) {
	s->top = -1;
}

void Stack_push(Stacktype* s, char item) {
	s->stack[++(s->top)] = item;
	return;
}

bool is_empty(Stacktype* s) {
	return s->top == -1;
}

char Stack_pop(Stacktype* s) {
	char t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {
	printf("문자열을 입력하시오 : ");
	char input[MAX_SIZE];
	scanf_s("%s", input, sizeof(input));

	Stacktype s;
	Stack_init(&s);
	int i = 0;
	while (input[i] != NULL) { //문자열의 끝까지 반복
		if ('a' <= input[i] && 'z' >= input[i]) { //아스키코드 a~z사이일 경우 스택안에 i번째 문자를 넣어줌
			Stack_push(&s, input[i]);
		}
		else if ('A' <= input[i] && 'Z' >= input[i]) { //아스키코드 A~Z사이일 경우 스택안에 소문자 문자(i번째 문자열-32)를 넣어줌
			Stack_push(&s, input[i]- 32);
		}
		i++;							//조건문이 끝나면 i 증가
	}	
	bool door = true; //회문은 참의 값을 가지고 있다.
	i = 0;			//밑에 while문을 위한 i 초기화
	while (input[i] != NULL) {  //문자열의 끝까지 반복
		if ('a' <= input[i] && 'z' >= input[i]) { //아스키코드 a~z 사이일경우 pop해줌
			if (Stack_pop(&s) != input[i]) { //pop한 문자가 i번째 문자와 다를 경우 false값
				door = false;
				break;
			}
		}
		else if ('A' <= input[i] && 'Z' >= input[i]) {  //아스키코드 A~Z 사이일경우 pop해줌
			if (Stack_pop(&s) != input[i]-32) { //pop한 문자가 i번째 문자와 다를 경우 false값
				door = false;
				break;
			}
		}
		i++;		//조건문이 끝나면 i 증가
	}

	if (door) {
		printf("회문 입니다");
	}
	else {
		printf("회문이 아닙니다");
	}
}