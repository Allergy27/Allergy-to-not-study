#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Guess(int secret);

int main() {
    int secret = 0;
    srand(time(NULL));
    secret = 1 + rand() % 100;
    Guess(secret);
    return 0;
}

void Guess(int secret) {
    int guess, count = 0;
    for(int i = 0;i < 8;++i) {
        printf("请输入一个整数：");
        scanf("%d", &guess);
        ++count;
        if(guess == secret)break;
        else if(guess > secret)printf("大了\n");
        else printf("小了\n");
    }
    if(count < 8)printf("恭喜，猜对了！共猜测%d次！\n", count);
    else printf("超过次数，游戏结束！\n");
}