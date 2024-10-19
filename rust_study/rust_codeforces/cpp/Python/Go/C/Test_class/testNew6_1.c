#include<stdio.h>

int main() {
    for(int i = 1;i < 10;++i)
        for(int j = 1;j <= i;++j)
            printf("%d*%d=%-2d%c", j, i, j * i, j == i ? '\n' : ' ');
    getchar();getchar();
    return 0;
}