#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DataType int

// 动态数组（线性表）
typedef struct Vector_DataType {
    DataType *data;
    int len, limit;
}vector;

vector vec_new(int x) {
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
        free(list);
    }
    vec->data[vec->len++] = x;
}

int main() {
    vector qwq = vec_new(0);
    for(int i = 0;i < 10;++i)vec_push(&qwq, i);
    for(int i = 0;i < qwq.len;++i)printf("%d ", qwq.data[i]);
    getchar();getchar();
    return 0;
}