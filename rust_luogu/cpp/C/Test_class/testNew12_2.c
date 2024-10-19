#include<stdio.h>

int main() {
    int A[10] = { 2, 3, 5, 7, 8, 10, 12, 15, 19, 21 };
    int i = 0, j = 9, n,flag=-1;
    scanf("%d", &n);
    while(i <= j) {
        int m = i + j >> 1;
        if(A[m] == n) {
            flag = m;
            break;
        }
        else if(A[m] > n)j = m - 1;
        else if(A[m] < n)i = m + 1;
    }
    if(flag + 1)printf("%d", flag);
    else printf("不存在");
    getchar();getchar();
    return 0;
}