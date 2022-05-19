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
	printf("���ڿ��� �Է��Ͻÿ� : ");
	char input[MAX_SIZE];
	scanf_s("%s", input, sizeof(input));

	Stacktype s;
	Stack_init(&s);
	int i = 0;
	while (input[i] != NULL) { //���ڿ��� ������ �ݺ�
		if ('a' <= input[i] && 'z' >= input[i]) { //�ƽ�Ű�ڵ� a~z������ ��� ���þȿ� i��° ���ڸ� �־���
			Stack_push(&s, input[i]);
		}
		else if ('A' <= input[i] && 'Z' >= input[i]) { //�ƽ�Ű�ڵ� A~Z������ ��� ���þȿ� �ҹ��� ����(i��° ���ڿ�-32)�� �־���
			Stack_push(&s, input[i]- 32);
		}
		i++;							//���ǹ��� ������ i ����
	}	
	bool door = true; //ȸ���� ���� ���� ������ �ִ�.
	i = 0;			//�ؿ� while���� ���� i �ʱ�ȭ
	while (input[i] != NULL) {  //���ڿ��� ������ �ݺ�
		if ('a' <= input[i] && 'z' >= input[i]) { //�ƽ�Ű�ڵ� a~z �����ϰ�� pop����
			if (Stack_pop(&s) != input[i]) { //pop�� ���ڰ� i��° ���ڿ� �ٸ� ��� false��
				door = false;
				break;
			}
		}
		else if ('A' <= input[i] && 'Z' >= input[i]) {  //�ƽ�Ű�ڵ� A~Z �����ϰ�� pop����
			if (Stack_pop(&s) != input[i]-32) { //pop�� ���ڰ� i��° ���ڿ� �ٸ� ��� false��
				door = false;
				break;
			}
		}
		i++;		//���ǹ��� ������ i ����
	}

	if (door) {
		printf("ȸ�� �Դϴ�");
	}
	else {
		printf("ȸ���� �ƴմϴ�");
	}
}