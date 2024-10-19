#include<stdio.h>
int ComFactor(int m, int n);

int main() {
    int x, y, factor;
    printf("请输入两个整数：");
    scanf("%d%d", &x, &y);
    factor = ComFactor(x, y);
    printf("%d和%d的最小公倍数是：%d\n", x, y, x * y / factor);
    getchar();getchar();
    return 0;
}

int ComFactor(int m, int n) {
    int r;
    r = m % n;
    while(r != 0) {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}