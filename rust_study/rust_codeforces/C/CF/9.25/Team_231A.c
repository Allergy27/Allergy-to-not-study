#include <stdio.h>
/*
这是CF的第231A题,输出能够完成的题目数量
*/
int main(){
    int n,a,b,c,ans=0;//初始化一些变量,ans用于记录最终的答案
    
    scanf("%d",&n);//接下来有n行数据
    for(int i=0;i<n;++i){
        scanf("%d%d%d",&a,&b,&c);
        ans+=(a+b+c>1? 1:0);//是否能够完成该题目
    }
    printf("%d",ans);//输出结果
    return 0;
}