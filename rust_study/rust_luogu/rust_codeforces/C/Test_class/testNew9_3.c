#include<stdio.h>
#include<stdlib.h>
typedef struct linklist {
    int val;
    struct linklist *next;
}lt;



int main() {
    lt *qwq, *head = (lt *) malloc(sizeof(lt));
    head->val = 1;
    qwq = head;
    int n, count = 1;
    printf("有几个人呢：");
    scanf("%d", &n);
    for(int i = 2;i <= n;++i) {
        lt *qaq = (lt *) malloc(sizeof(lt));
        qaq->val = i;
        qaq->next = NULL;
        qwq->next = qaq;
        qwq = qwq->next;
    }
    qwq->next = head;qwq = qwq->next;
    while(qwq->next != qwq) {
        if(!count)qwq->next = qwq->next->next;
        qwq = qwq->next;
        count = (count + 1) % 2;
    }
    printf("最后剩下的是%d\n", qwq->val);
    getchar();getchar();
    return 0;
}
