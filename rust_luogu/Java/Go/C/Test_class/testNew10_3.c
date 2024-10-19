#include<stdio.h>

int strlenth(char *);
void strswap(char *, char *);
int main() {
    char qwq[100], qaq[100];
    scanf("%s%s", qwq, qaq);
    printf("%d\n", strlenth(qwq));
    strswap(qwq, qaq);
    printf("%s %s\n", qwq, qaq);
    getchar();getchar();
    return 0;
}
int strlenth(char *str) {
    int i = 0;
    while(*(str + i++) != 0)continue;
    return i - 1;
}
void strswap(char *str1, char *str2) {
    char tmp = 0;
    int i = 0;
    while(*(str1 + i) != 0 || *(str2 + i) != 0) {
        tmp = *(str1 + i);
        *(str1 + i) = *(str2 + i);
        *(str2 + i++) = tmp;
    }
}