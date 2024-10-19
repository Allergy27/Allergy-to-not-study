#include<stdio.h>

void sort(int *, int);

int main() {
    int qwa[] = { 9, 8, 7, 56, 7, 3, 2, 25, 1, 0 };
    for(int i = 0;i < 10;++i)printf("%d ", qwa[i]);
    printf("\n");
    sort(qwa, 10);
    for(int i = 0;i < 10;++i)printf("%d ", qwa[i]);
    getchar();getchar();
    return 0;
}
void sort(int *qwq, int size) {
    int *qaq = qwq;
    for(int i = 0;i < size;++i)
        for(int j = size - i;j < size;++j)
            if(*(qaq + j) < *(qaq + j - 1)) {
                *(qaq + j) ^= *(qaq + j - 1);
                *(qaq + j - 1) ^= *(qaq + j);
                *(qaq + j) ^= *(qaq + j - 1);
            }
}