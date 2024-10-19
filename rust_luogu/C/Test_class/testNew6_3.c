#include<stdio.h>

int main() {
    int count = 0;
    for(int i = 0;i < 34;++i) {
        for(int j = 0;j < 51;++j) {
            for(int k = 0;k < 201;k += 2) {
                if(i + j + k == 100 && (3 * i + 2 * j + k / 2) == 100) {
                    printf("%d,%d,%d\n", i, j, k);
                    ++count;
                }
            }
        }
    }
    printf("count=%d", count);
    getchar();getchar();
    return 0;
}