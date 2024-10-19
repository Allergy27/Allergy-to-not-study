#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
    srand(time(NULL));
    int qwq[10];
    // for(int i = 0;i < 10;++i)printf("%d\n",rand() % 100);
    for(int i = 0;i < 10;++i)scanf("%d", &qwq[i]);
    for(int i = 10;i > 0;--i)
        for(int j = 0;j + 1 < i;++j) {
            if(qwq[j] > qwq[j + 1]) {
                qwq[j] ^= qwq[j + 1];
                qwq[j + 1] ^= qwq[j];
                qwq[j] ^= qwq[j + 1];
            }
        }
    for(int i = 0;i < 10;++i)printf("%d ", qwq[i]);
    getchar();getchar();
    return 0;
}