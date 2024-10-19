#include<stdio.h>
void tj();
int main() {
    tj();
    getchar();getchar();
    return 0;
}
void tj() {
    char qwq[1005] = { 0 };
    int qvq[] = { 0, 0, 0, 0 }; //数字 空格 大写 小写
    gets(qwq);
    int i = -1;
    while(qwq[++i] != 0) {
        if('0' <= qwq[i] && qwq[i] <= '9')++qvq[0];
        if(qwq[i] == ' ')++qvq[1];
        if('A' <= qwq[i] && qwq[i] <= 'Z')++qvq[2];
        if('a' <= qwq[i] && qwq[i] <= 'z')++qvq[3];
    }
    printf("%d %d %d %d %d", qvq[2] + qvq[3], qvq[0], qvq[1], qvq[2], qvq[3]);
}