#include<stdio.h>

int main(){
    int n,i,min=0,max=0;double ans[100005]={0};
    double answer;
    scanf("%d",&n);
    scanf("%lf",&ans[0]);//获取第一个输入
    for(i=1;i<n;++i){
        scanf("%lf",&ans[i]);
        if(ans[i]<ans[min])min=i;//找最小值索引

        if (ans[i]>ans[max])max=i;//找最大值索引
    }
    answer=(ans[min]+ans[max])/2.0;//将答案定为最大值和最小值的均值
    ans[min]=answer;ans[max]=answer;//将最大和最小值变为均值

    for(i=0;i<n;++i)if(ans[i]<answer)answer=ans[i];//找最小值作为答案

    printf("%.1lf",answer);
    //getchar();getchar();
    return 0;
}