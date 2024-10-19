#include<stdio.h>

void tj(int *);

int main() {
    int m = 3, ans[3][4];
    while(m--)tj(ans[2 - m]);
    for(int i = 0;i < 12;++i) {
        if(i != 0 && i % 4 == 0)printf("\n");
        printf("%d ", ans[i / 4][i % 4]);
    }
    getchar();getchar();
    return 0;
}
void tj(int *res) {
    char qwq[42] = { 0 };
    int qvq[] = { 0, 0, 0, 0 }; //大写 小写 空格 其他
    gets(qwq);
    int i = -1;
    while(qwq[++i] != 0) {
        if(qwq[i] == ' ')++qvq[2];
        else if('A' <= qwq[i] && qwq[i] <= 'Z')++qvq[0];
        else if('a' <= qwq[i] && qwq[i] <= 'z')++qvq[1];
        else ++qvq[3];
    }
    for(int i = 0;i < 4;++i)*(res + i) = qvq[i];
}