#include<stdio.h>

int main() {
    int mounth, pre = 1, now = 1;
    printf("请输入月份：");
    scanf("%d", &mounth);
    for(int i = 2;i < mounth;++i) {
        now += pre;
        pre = now - pre;
    }
    printf("第%d月的兔子一共%d只", mounth, now);
    getchar();getchar();
    return 0;
}