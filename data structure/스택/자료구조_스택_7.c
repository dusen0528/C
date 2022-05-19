
/*
���� ��ȣ�� ���ö����� ��ȣ ��ȣ�� �ϳ��� �����ϰ� ������ ��ȣ�� ������ ��Ī�Ǵ� ���� ��ȣ ��ȣ�� ����Ѵ�
�� �����Ϸ��� (�� ���������� stack�� count�� �����ϰ� 1�÷��ش�
)�� �������� stack���� pop�� �Ѵ�
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_NO_SECURE_WARNINGS
#define Stack_MAX_SIZE 1000

typedef struct {
    int stack[Stack_MAX_SIZE];
    int top;
}Stack_a;

void init_stack(Stack_a* s) {
    s->top == -1;
}

int is_empty(Stack_a* s) {
    return (s->top == -1);
}

int is_full(Stack_a* s) {
    return (s->top == Stack_MAX_SIZE - 1);
}

void push(Stack_a* s, int items) {
    if (is_full(s)) {
        fprintf(stderr, "������ȭ\n");
        return;
    }
    else {
        s->stack[++(s->top)] = items;
        return;
    }

}

int pop(Stack_a* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� �������");
        exit(1);
    }
    else {
        return s->stack[(s->top)--];
    }
}


int main(void) {
    Stack_a s;
    init_stack(&s);
    char susik[Stack_MAX_SIZE];
    printf("���� : ");
    scanf("%s", susik);
    int len = strlen(susik);
    printf("��ȣ �� :");
    int count = 1;
    for (int i = 0; i < len; i++) {

        if (susik[i] == '(') {
            push(&s, count);
            printf("%d", count);
            count++;
        }
        else if (susik[i] == ')') {
            printf("%d", pop(&s));
        }

    }


}





//scanf_s("%s", &susik, sizeof(susik));