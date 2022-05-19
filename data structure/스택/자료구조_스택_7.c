
/*
왼쪽 괄호가 나올때마다 괄호 번호는 하나씩 증가하고 오른쪽 괄호가 나오면 매칭되는 왼쪽 괄호 번호를 출력한다
를 구현하려면 (를 만날때마다 stack의 count를 저장하고 1올려준다
)를 만날때는 stack에서 pop을 한다
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
        fprintf(stderr, "스택포화\n");
        return;
    }
    else {
        s->stack[++(s->top)] = items;
        return;
    }

}

int pop(Stack_a* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 비어있음");
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
    printf("수식 : ");
    scanf("%s", susik);
    int len = strlen(susik);
    printf("괄호 수 :");
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