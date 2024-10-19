#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DataType int
#define N 500027

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

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int u, int v) {
    int t1 = find(u);
    int t2 = find(v);
    if(t1 != t2)F[t1] = t2;
}

int tarjin(int q) {

}

int main() {
    int n;
    scanf("%d", &n);
    gird qwq = g_new(n + 1);
    vector a = vec_new(n);
    vector b = vec_new(n);
    for(int i = 0;i < n - 1;++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a.data[i] = x;
        b.data[i] = y;
    }
    for(int i = 0;i < n - 1;++i) {
        qwq.data[a.data[i]][b.data[i]] = 1;
        qwq.data[b.data[i]][a.data[i]] = 1;
    }
    int x, y;
    scanf("%d%d", &x, &y);
    int p = dfs(qwq, 1, 0, n, x, y);
    printf("%d", p);
    getchar();getchar();
    return 0;
}