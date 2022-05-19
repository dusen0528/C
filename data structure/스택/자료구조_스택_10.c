#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
주어진 정수에서 반복되는 숫자를 제거하는 프로그램
정수 입력 : 1222233
출력 : 123
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
        fprintf(stderr, "스택포화\n");
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
        fprintf(stderr, "스택 비어있음");
        exit(1);
    }
    else {
        s->size--;
        return s->stack[(s->top)--];
    }
}

int peek(Stack_a* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 비어있음");
        exit(1);
    }
    return s->stack[(s->top)];
}


int main(void) {
    Stack_a A;
    char input[Stack_MAX_SIZE];
    init_stack(&A);
    printf("정수를 입력하시오 : ");
    scanf("%s", input, sizeof(input));
  
    for (int i = 0; input[i] != '\0'; i++) { //널값이 나오기전까지 반복함
        if (is_empty(&A)) { //만약 스택이 비어있으면 input[i]를 스택에 넣어줌
            push(&A, input[i]);
        
        }
        else if (peek(&A) == input[i]) { //스택에 담긴 값이 현재 문자와 일치한다면 코드를 건너뜀
            continue;
        }
        else { //스택에 담긴 값이 현재 문자와 다르다면그 전에 담긴 문자를 출력 후 현재 문자를 스택에 넣어줌
          
            printf("%c", pop(&A));
            push(&A, input[i]);
            
        }

    }
    //널값으로 반복문이 종료되고 현재 스택에는 문자가 남아있으므로 꺼내줌

    printf("%c", pop(&A));



}