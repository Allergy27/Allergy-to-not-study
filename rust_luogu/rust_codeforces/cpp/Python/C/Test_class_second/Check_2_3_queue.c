#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DataType int

// 入队 出队 取队首 判空 销毁
typedef struct node_DataType {
    DataType data;
    struct node_DataType *next;
}node;

typedef struct queue_DataType {
    node *head;
    node *tile;
}queue;

queue *queue_new(){
    queue * x = (queue *) malloc(sizeof(queue));
x->head = NULL;
x->tile = NULL;
return x;
}

void queue_push(queue *que, DataType val) {
    node *x = (node *) malloc(sizeof(node));
    x->data = val;
    x->next = NULL;
    if(que->head == NULL) {
        que->head = x;
        que->tile = x;
        return;
    }
    que->tile->next = x;
    que->tile = x;
}

DataType queue_get(queue *que) {
    if(que->head == NULL) {
        puts("[WARNING] 队列为空，获取失败，返回 0");
        return 0;
    }
    return que->head->data;
}

DataType queue_pop(queue *que) {
    if(que->head == NULL) {
        puts("[WARNING] 队列为空，删除失败，返回 0");
        return 0;
    }
    DataType x = que->head->data;
    que->head = que->head->next;
    return x;
}

void queue_free(queue *que) {
    node *pre = que->head;
    node *now = que->head->next;
    while(pre != NULL) {
        free(pre);
        pre = now;
        now = now->next;
    }
}
int main() {
    queue *qwq = queue_new();
    for(int i = 0;i < 10;++i)queue_push(qwq, i);
    for(int i = 0;i < 11;++i)printf("%d\n", queue_pop(qwq));
    queue_free(qwq);
    getchar();getchar();
    return 0;
}