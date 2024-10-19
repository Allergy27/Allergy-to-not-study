#include<stdio.h>

int birth(int);

int main() {
    printf("要知道第几个人的年龄？请输入：");
    int n;
    scanf("%d", &n);
    printf("第%d个人的年龄是:%d", n, birth(n));
    getchar();getchar();
    return 0;
}
int birth(int x) {
    if(x == 1)return 10;
    return 2 + birth(x - 1);
}
