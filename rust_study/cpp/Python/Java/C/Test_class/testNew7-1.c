#include<stdio.h>

int main() {
    int n = 0, qwq[1005], low = 0, high = 0;
    double evr = 0;
    char res[100];
    while(gets(res) != "" && res[0] != 0) {
        int i = 0, t = 0;
        while(res[i] != 0)t = t * 10 + res[i++] - '0';
        qwq[n] = t;
        evr += qwq[n++];
    }
    evr = evr / n;
    for(int i = 0;i < n;++i) {
        if(qwq[i] < evr)++low;
        if(qwq[i] >= evr)++high;
    }
    printf("成绩平均值为:%.2lf\n高出平均分的有%d个，低于平均分的有%d个", evr, high, low);
    getchar();getchar();
    return 0;
}