#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10001

int tree[N][N], depth[N], n, find[N];

void dfs(int node, int  fa) {
    for(int i = 1;i <= n;++i)
        if(tree[node][i] && i != fa) //下方分别是记录父亲、深度、搜索孩子
            find[i] = node, depth[i] = depth[node] + 1, dfs(i, node);
}
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main() {
    int x, y;
    scanf("%d", &n);
    for(int i = 1;i < n;++i) {
        scanf("%d%d,", &x, &y);
        tree[x][y] = 1;
        tree[y][x] = 1;
    }
    dfs(1, 0); //默认1为根节点
    scanf("%d%d", &x, &y);
    if(depth[x] < depth[y])swap(&x, &y);
    while(depth[x] > depth[y])x = find[x]; //回溯
    while(x != y)x = find[x], y = find[y];
    printf("%d", x);
    return 0;
}
