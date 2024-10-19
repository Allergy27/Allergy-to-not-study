#include<stdio.h>
int n_pp(int);

int main() {
    int n;
    printf("请输入一个数n：");
    scanf("%d", &n);
    printf("它的阶乘为：%d", n_pp(n));
    getchar();getchar();
    return 0;
}

int n_pp(int x) {
    if(x == 1)return 1;
    return x * n_pp(x - 1);
}