#include<stdio.h>

int main() {
    int count = 0, res = 0;
    char qwq[100] = { 0 };
    printf("请输入一行英文句子；");
    gets(qwq);
    for(int i = 0;i < 100;++i) {
        if(qwq[i] == 0)break; //到结束符了
        else if('a' < qwq[i] && qwq[i] < 'z' || 'A' < qwq[i] && qwq[i] < 'Z')res = 1;
        else if(res)res = ++count == 0;
    }
    printf("在这个句子中有%d个单词", res ? count + 1 : count);
    getchar();getchar();
    return 0;
}