#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 2000000


typedef int element;
typedef struct {
    element data[MAX_SIZE];
    int front, rear;
}QueueType; //ť ����ü ����

void init_queue(QueueType* q) {
    q->front = -1;
    q->rear = -1;
} //ť �ʱ�ȭ

int is_empty(QueueType* q) {
    return (q->front == q->rear);
} //front�� rear���� ���� ��� ��� ����

int size(QueueType* q) {
    if (is_empty(q)) return 0;
    return(q->rear - q->front);
}

void push(QueueType* q, element item) {
    q->data[++(q->rear)] = item;
}

element pop(QueueType* q) {
    if (is_empty(q)) return -1;
    return q->data[++(q->front)]; 
}

int front(QueueType* q) {
    if (is_empty(q)) return -1;
    return q->data[q->front+1];
}

int back(QueueType* q) {
    if (is_empty(q)) return -1;
    return q->data[q->rear];
}

int main(void) {
    QueueType q;
    init_queue(&q);

    int N;
    scanf("%d", &N);
   
    while (1) {
        char str[6];
        scanf("%s", str);
        if (!strcmp(str, "push")) {
            int data = 0;
            scanf("%d", &data);
            push(&q, data);
        }
        else if (!strcmp(str, "front")) {
            printf("%d\n", front(&q));
        }
        else if (!strcmp(str, "back")) {
            printf("%d\n", back(&q));
        }
        else if (!strcmp(str, "pop")) {
            printf("%d\n", pop(&q));
        }
        else if (!strcmp(str, "size")) {
            printf("%d\n", size(&q));
        }
        else if (!strcmp(str, "empty")) {
            printf("%d\n", is_empty(&q));
        }
        N--;
        if (N == 0) break;

    }


    return 0;
}





