#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct vectorint {
    int *val;
}vector;

void new(vector *qwq, int n){
    qwq->val = (int *) malloc(n * sizeof(int));
    memset(qwq->val, 0, n * sizeof(int));
}

int main() {
    int n;
    scanf("%d", &n);
    vector a;
    new(&a, n);
    for(int i = 0;i < n;++i)a.val[i] = i;
    for(int i = 0;i < n;++i)printf("%d ", a.val[i]);
    getchar();getchar();
    return 0;
}