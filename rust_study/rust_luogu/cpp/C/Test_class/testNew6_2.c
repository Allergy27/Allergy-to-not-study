#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;++i)
        for(int j = 0;j <= i;++j)
            printf("%c%c", 'A' + n - j - 1, j == i ? '\n' : '\0');
    getchar();getchar();
    return 0;
}