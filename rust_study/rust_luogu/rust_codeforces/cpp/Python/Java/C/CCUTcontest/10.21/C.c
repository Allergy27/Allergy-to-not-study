#include<stdio.h>

int main(){
    int n,i,j,ans[9]={0};
    scanf("%d",&n);
    for(i=0;i<n;++i){
        int num=1 , min=9 ,lenth, minIndex=0;//声明些有用的变量
        scanf("%d",&lenth);
        for(j=0 ; j < lenth ; ++j){
            scanf("%d",&ans[j]);
            if(ans[j] < min){//一边遍历输入一边找最小值
                min = ans[j];
                minIndex = j;//最小值的索引
            }
        }
        for(j=0;j < lenth;++j){//再次遍历,获取乘积
            num *= j==minIndex ? ans[j]+1:ans[j];//当遇到标记的最小值时使其+1
        }
        printf("%d\n",num);
    }
    return 0;
}