#include<stdio.h>
#define maxN 10
int Broad[maxN], UN[maxN], sum = 0;

int main() {
    int n;scanf("%d", &n);
    void dfs(int, int);
    dfs(0, n);//从第0个开始搜索
    getchar();getchar();
    return 0;
}
void dfs(int i, int N) {
    int j;
    for(j = 0;j < N;++j) {
        if(!Broad[j]) {
            UN[i] = j + 1;
            Broad[j] = 1;
            if(i == N - 1) {
                for(int t = 0;t < N;++t)printf("%5d", UN[t]);
                printf("\n");
            }
            else dfs(i + 1, N);//搜索下一行
            Broad[j] = 0;//回溯
        }
    }
}