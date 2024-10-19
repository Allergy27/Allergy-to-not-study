#include<stdio.h>

int main(){
    char N[15]={10},n[15]={10};
    scanf("%s%s",N,n);
    /*
    前面是(N+1)/2个,(后面是N/2个数->不用算
    所以要写一个高精除低精
    然后结果就等于n>(N+1)/2? (n-((N+1)/2))*2:n*2+1
    所以要写一个高精乘低精
    题目不难，烦的是高精*/
    
    //除比较简单,每一位,/=2再+=进位标识*5,进位标识为%=2,对每一位操作,直到到头
    
    //将N处理成(N+1)/2
    char i=0,j=0,flag_pre=0,flag_now=0;
    while(N[i]!=0){
        N[i]-='0';
        flag_now=N[i]%2;
        N[i]/=2;
        N[i]+=flag_pre*5;
        flag_pre=flag_now;
        if(N[i]>0)N[i]+='0';//反正也不输出,无所谓了
        ++i;
    }
    //乘需要掉转方向,等会写
    char num[15];//掉转后的(N+1)/2
    for(i=14;i>=0;--i){
        if(N[i]!=0)num[j]=N[i];
        ++j;
    }
    
    getchar();getchar();
    return 0;
}