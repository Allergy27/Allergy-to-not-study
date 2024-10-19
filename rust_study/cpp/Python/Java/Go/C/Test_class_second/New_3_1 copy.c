#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

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

void swap(int *a, int *b) {
    int k = *a;
    *a = *b;
    *b = k;
}
int __lg(int n) {
    int count = 0;
    while(n > 1) {
        n >>= 1;
        count++;
    }
    return count;
}

int n, m, R, dn, dfn[N], mi[19][N];
int get(int x, int y) { return dfn[x] < dfn[y] ? x : y; }
void dfs(int id, int f, int n) {
    mi[0][dfn[id] = ++dn] = f;
    for(int t = 1;t <= n;++t) if(t != f) dfs(t, id, n);
}
int lca(int u, int v) {
    if(u == v) return u;
    if((u = dfn[u]) > (v = dfn[v])) swap(&u, &v);
    int d = __lg(v - u++);
    return get(mi[d][u], mi[d][v - (1 << d) + 1]);
}

int main() {
    int n;
    scanf("%d", &n);
    gird qwq = g_new(n + 2);
    vector a = vec_new(n);
    vector b = vec_new(n);
    for(int i = 0;i < n - 1;++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a.data[i] = x;
        b.data[i] = y;
    }
    for(int i = 0;i < n - 1;++i) {
        mi[a.data[i]][b.data[i]] = 1;
        mi[b.data[i]][a.data[i]] = 1;
    }
    int x, y;
    scanf("%d%d", &x, &y);
    dfs(R, 0, n);
    for(int i = 1; i <= __lg(n); i++)
        for(int j = 1; j + (1 << i) - 1 <= n; j++)
            mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
    scanf("%d%d", &x, &y);
    printf("%d\n", lca(x, y));
    getchar();getchar();
    return 0;
}