#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DataType int

// 交换排序
typedef struct Vector_DataType {
    DataType *data;
    int len, limit;
}vector;

vector vec_new(int x){
    vector list;
list.data = (DataType *) malloc(x * sizeof(DataType));
memset(list.data, 0, x * sizeof(DataType));
list.len = x;
list.limit = x;
return list;
}

void vec_push(vector *vec, int x) {
    if(vec->len == vec->limit) { //扩容
        if(vec->limit > 0)vec->limit <<= 1;
        else vec->limit = 10;
        DataType *list = (DataType *) malloc(vec->limit * sizeof(DataType));
        for(int i = 0;i < vec->limit >> 1;++i)list[i] = vec->data[i];
        vec->data = list;
    }
    vec->data[vec->len++] = x;
}

void MERGE_SORT(vector *list, int p, int r) {
    if(p < r) {
        int q = p + r >> 1;
        MERGE_SORT(list, p, q);
        MERGE_SORT(list, q + 1, r);
        vector L = vec_new(0);
        vector R = vec_new(0);
        for(int x = p;x <= q;++x)vec_push(&L, list->data[x]);
        for(int x = q + 1;x <= r;++x)vec_push(&R, list->data[x]);
        int a = 0, b = 0;
        for(int t = p;t <= r;++t) {
            if(b == r - q) list->data[t] = L.data[a++];
            else if(a == q - p + 1) list->data[t] = R.data[b++];
            else if(L.data[a] <= R.data[b]) list->data[t] = L.data[a++];
            else list->data[t] = R.data[b++];
        }
    }
}

int main() {
    vector qwq = vec_new(0);
    for(int i = 0;i < 10;++i)vec_push(&qwq, 10 - i);
    MERGE_SORT(&qwq, 0, qwq.len - 1);
    for(int i = 0;i < qwq.len;++i)printf("%d ", qwq.data[i]);
    free(qwq.data);
    getchar();getchar();
    return 0;
}