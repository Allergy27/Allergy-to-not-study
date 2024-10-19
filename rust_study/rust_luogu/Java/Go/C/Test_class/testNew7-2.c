#include<stdio.h>
#define nke 2
int main() {
    printf("请输入学生人数：");
    int i = 0, n;
    scanf("%d", &n);
    double res[100][nke + 2];
    while(++i <= n) {
        printf("请输入第%d个学生的语文成绩和数学成绩：", i);
        for(int j = 0;j < nke;++j) {
            scanf("%lf", &res[i][j]);
            res[i][nke] += res[i][j];
        }
        res[i][nke + 1] = res[i][nke] / 1.0 / nke;
    }
    --i;
    printf("\n  编号 语文成绩 数学成绩 总成绩 平均成绩\n");
    int qvq[6] = { 0 };
    while(i-- > 0)printf("     %d\t    %.0lf\t     %.0lf\t    %.0lf    %.2lf\n", n - i, res[n - i][0], res[n - i][1], res[n - i][2], res[n - i][3]);
    getchar();getchar();
    return 0;
}