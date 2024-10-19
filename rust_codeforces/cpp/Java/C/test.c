#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int a, b;
    printf("完全");
    scanf("%d %d", &a, &b);
    double ans = a * b * 0.10;
    printf("%lf\n", ans);
    getchar();
    getchar();
    return 0;
}
