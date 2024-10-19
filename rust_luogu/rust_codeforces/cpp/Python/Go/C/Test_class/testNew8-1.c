#include<stdio.h>

void prime(int);

int main() {
    int n;
    printf("请输入n：");
    scanf("%d", &n);
    prime(n);
    getchar();getchar();
    return 0;
}
void prime(int x) {
    for(int i = 2;i < x;++i)if(x % i == 0) { printf("NO"); return; }
    printf("YES");
}