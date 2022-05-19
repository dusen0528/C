#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
�־��� �������� �ݺ��Ǵ� ���ڸ� �����ϴ� ���α׷�
���� �Է� : 1222233
��� : 123
*/

#define Stack_MAX_SIZE 100

typedef struct {
    char stack[Stack_MAX_SIZE];
    int top;
    int size;
}Stack_a;

void init_stack(Stack_a* s) {
    s->top = -1;
    s->size = 0;
}

int is_empty(Stack_a* s) {
    return (s->top == -1);
}

int is_full(Stack_a* s) {
    return (s->top == Stack_MAX_SIZE - 1);
}

void push(Stack_a* s, char items) {
    if (is_full(s)) {
        fprintf(stderr, "������ȭ\n");
        return;
    }
    else {
        s->stack[++(s->top)] = items;
        s->size++;
        return;
    }

}

int pop(Stack_a* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� �������");
        exit(1);
    }
    else {
        s->size--;
        return s->stack[(s->top)--];
    }
}

int peek(Stack_a* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� �������");
        exit(1);
    }
    return s->stack[(s->top)];
}


int main(void) {
    Stack_a A;
    char input[Stack_MAX_SIZE];
    init_stack(&A);
    printf("������ �Է��Ͻÿ� : ");
    scanf("%s", input, sizeof(input));
  
    for (int i = 0; input[i] != '\0'; i++) { //�ΰ��� ������������ �ݺ���
        if (is_empty(&A)) { //���� ������ ��������� input[i]�� ���ÿ� �־���
            push(&A, input[i]);
        
        }
        else if (peek(&A) == input[i]) { //���ÿ� ��� ���� ���� ���ڿ� ��ġ�Ѵٸ� �ڵ带 �ǳʶ�
            continue;
        }
        else { //���ÿ� ��� ���� ���� ���ڿ� �ٸ��ٸ�� ���� ��� ���ڸ� ��� �� ���� ���ڸ� ���ÿ� �־���
          
            printf("%c", pop(&A));
            push(&A, input[i]);
            
        }

    }
    //�ΰ����� �ݺ����� ����ǰ� ���� ���ÿ��� ���ڰ� ���������Ƿ� ������

    printf("%c", pop(&A));



}