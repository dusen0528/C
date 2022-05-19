#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
4a3b�� a�� 4 b�� 3���ִ�.
�� ����� �����̾����̶�� �ϴµ�,
�ҹ��ڿ� �빮�ڴ� ���� x
�� �����Ϸ���
������ �ΰ� �����Ѵ�
*/

#define Stack_MAX_SIZE 100
#define countsize 100
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
    int count;
    char input[Stack_MAX_SIZE];
    init_stack(&A);
    printf("���ڿ��� �Է��Ͻÿ�: ");
    scanf("%s", input, sizeof(input));
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += 32;
        }
    }
    for (int i = 0; input[i] != '\0'; i++) { //�ΰ��� ������������ �ݺ���
        if (is_empty(&A)) { //���� ������ ��������� input[i]�� ���ÿ� �־���
            push(&A, input[i]);
            count = 1;
        }
        else if (peek(&A) == input[i]) { //���ÿ� ��� ���� ���� ���ڿ� ��ġ�Ѵٸ� count�� 1 �÷���
            count++;

        }
        else { //���ÿ� ��� ���� ���� ���ڿ� �ٸ��ٸ� ī��Ʈ�� �� ���� ��� ���ڸ� ��� �� ���� ���ڸ� ���ÿ� �ְ� ī��Ʈ�� 1�� �ʱ�ȭ ������
            printf("%d", count);
            printf("%c", pop(&A));
            push(&A, input[i]);
            count = 1;
        }

    }
    //�ΰ����� �ݺ����� ����ǰ� ���� ���ÿ��� ���ڰ� ���������Ƿ� ������
    printf("%d", count);
    printf("%c", pop(&A));



}