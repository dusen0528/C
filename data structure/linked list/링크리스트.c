#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct nd{
    node *head;
    node *tail;
}nd;

node* Creat(int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
    /*
    노드 생성 함수 단, 연결되어 있지 않은 상태
    생성된 노드는 NULL을 가리키고 있으며 data를 가지고 있음
    */
}

void first_add(nd* newnd, int data){
    /*
    헤드 오른쪽(첫번째)에 노드를 연결하는 함수
    매개변수로 head와 tail을 가지고 있는 nd 구조체와 data를 받는다.
    */
    node *newnode = Creat(data);
    //새로운 노드 생성
    if(newnd->head==NULL){
        //만약nd->head가 NULL을 가리키고 있다 == 노드가 하나도 존재하지 않을 경우
        newnd->head = newnode;
        newnd->tail = newnode;
        //처음 연결한 리스트이기에 head와 tail은 NULL이 아닌 새로 추가된 newnode를 가리킨다
    }
    else{
        //NULL이 아닌 어떤 다른 주소를 가리키고 있을 경우 즉, 처음 연결하는 노드가 아닐 경우
        newnode->next = newnd->head;
        //newnode의 next는 nd구조체의 head가 가리키는 값
        newnd->head = newnode;
        //nd구조체의 head값은 newnode의 주소를 가리킨다
        //즉 ㅁ(1) ㅁ(2)이 있다면 head는 (2)의 주소를 가리키게 되는 것으로 ->방향 리스트의 왼쪽에 노드가 추가된다는 것
    }

}

void last_add(nd* newnd, int data){
    /*
    처음 연결된 노드 끝에서 삽입 하는 함수 (->방향 기준 오른쪽에)
    */
    node *newnode = Creat(data);
    //노드를 새로 만들고
    newnd->tail->next = newnode;
    //nd구조체의 tail->next는 새로 만든 newnode의 주소값을 저장
    newnd->tail = newnode;
    //tail은 newnode를 가리킴

}

void node_print(nd *newnd){
    node *p = newnd->head;
    while(p!=NULL) {
        printf("%d ->", p->data);
        p = p->next;
    }
}

//삭제 기능


int main(void){

    nd* nda = (nd*)malloc(sizeof(nd));
    
    nda->head = NULL;
    nda->tail = NULL;

    first_add(nda, 5);
    last_add(nda, 1);
    first_add(nda, 32);
    last_add(nda, 6);
    last_add(nda, 7);
    node_print(nda);

    return 0;

}
