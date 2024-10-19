#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DataType int

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

// 邻接矩阵
typedef struct Grid_DataType {
    DataType **data;
}gird;

gird g_new(int n) {
    gird list;
    list.data = (DataType **) malloc(n * sizeof(DataType *));
    for(int i = 0;i < n;++i) {
        DataType *data = (DataType *) malloc(n * sizeof(DataType));
        memset(data, 0, n * sizeof(DataType));
        list.data[i] = data;
    }
    return list;
}

int main() {
    gird qwq = g_new(5);
    printf("%d", qwq.data[0][1]);
    getchar();getchar();
    return 0;
}