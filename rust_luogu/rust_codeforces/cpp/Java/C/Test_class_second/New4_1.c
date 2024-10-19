#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int head = 0, tile = 1, n, k;

    scanf("%d%d", &n, &k);
    int f[10001] = { n }, check[10001] = { 0 }; //初始化顺便节约一行f[0]=n

    while(head < tile) { //模拟队列跑bfs
        int x = f[head++]; //取数
        if(x == k)break; //如果找到直接退出
        for(int i = 0;i < 3;++i) { //转移
            int c = i == 0 ? x + 1 : i == 1 ? x - 1 : x * 2; //条件表达式压行
            if(c >= 0 && !check[c])f[tile++] = c, check[c] = check[x] + 1;
        }
    }

    printf("%d", check[k]);
    return 0;
}
