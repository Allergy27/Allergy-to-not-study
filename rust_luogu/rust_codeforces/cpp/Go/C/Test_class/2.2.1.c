#include<stdio.h>

int main(){
    int M,N;
    int chicken,rabbit;
    printf("请输入头和脚的个数:");
    scanf("%d%d",&M,&N);
    chicken=0;
    for (chicken = 0; chicken <= M; chicken++){
        rabbit = M-chicken;                 
        if (2 * chicken + 4 * rabbit == N) break;
    }
    if(chicken<=M)printf("鸡有%d只，兔子有%d只\n",chicken,rabbit);
    else printf("输入数据不合理，无解\n");
    getchar();getchar();
    return 0;
}