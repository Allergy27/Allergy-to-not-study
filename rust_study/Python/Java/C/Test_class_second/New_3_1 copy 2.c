#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DataType int
#define N 500027

int fa[N], vis[N], lca[N], query[N][2];

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

void tarjan(gird tree, int q, int n) { //q表示当前遍历的节点
    vis[q]++; //标记为1
    for(int t = 1;t <= n;++t) { //枚举子节点
        if(!vis[t])  {//如果子节点还没有被访问
            tarjan(tree, t, n);     //遍历子节点
            fa[t] = q;    //合并子节点到当前节点
        }
    }
    for(auto t : query[q])//与q结点有关的询问t.second是问题编号，t.first是询问的另一个结点
    {
        int v = t.x, id = t.y;
        if(vis[v] == 2 && !lca[id])  //如果第id个问题还没有找到lca并且v节点已回溯
        {
            lca[id] = find(v);
        }

    }
    vis[q]++;  //标记为2 表示已回溯
}

void read(int *a, int *b) {
    a = (int) getchar();getchar();
    b = (int) getchar();getchar();
}

int main() {
    int n;
    scanf("%d", &n);
    vector fa = vec_new(n);
    gird qwq = g_new(n + 1);
    vector a = vec_new(n);
    vector b = vec_new(n);
    for(int i = 0;i < n - 1;++i) {
        int x, y;
        read(&x, &y);
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