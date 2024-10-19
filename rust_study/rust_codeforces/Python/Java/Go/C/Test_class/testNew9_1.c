#include<stdio.h>

void swap(int *, int *);
void change(int, int);

int main() {
    int a = 3, b = 6;
    printf("两个数原先是：%d %d\n", a, b);
    change(a, b);
    printf("调用传值函数：%d %d\n", a, b);
    swap(&a, &b);
    printf("调用传递地址：%d %d\n", a, b);
    getchar();getchar();
    return 0;
}
void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void change(int a, int b) {
    a ^= b;
    b ^= a;
    a ^= b;
}