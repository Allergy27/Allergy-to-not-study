#include<stdio.h>

int main() {
    int qwq[100] = { 0 }, n, num;
    printf("请输入数组长度：");
    scanf("%d", &n);
    for(int i = 0;i < n;++i)scanf("%d", &qwq[i]);
    printf("请输入要插入的数：");
    scanf("%d", &num);
    qwq[n] = num;
    for(int i = n;i > 0;--i)
        if(qwq[i] < qwq[i - 1]) { qwq[i] ^= qwq[i - 1];qwq[i - 1] ^= qwq[i];qwq[i] ^= qwq[i - 1]; }
    getchar();getchar();
    return 0;
}