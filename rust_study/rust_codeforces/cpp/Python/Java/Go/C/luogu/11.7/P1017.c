#include<stdio.h>

int main(){
    int N,R,i=0,Num[20]={0};
    scanf("%d%d",&N,&R);
    printf("%d=",N);
    while(N!=0){
        //该死的C，还得我调整一下除法才能满足条件
        Num[i++]=N%R<0?N%R-R:N%R;
        N=N>=0||N%R==0? N/R:N/R+1;
    }
    for(;--i>=0;)printf("%c",Num[i]<10? Num[i]+'0':Num[i]-10+'A');//转换一下，满足条件
    printf("(base%d)",R);
    getchar();getchar();
    return 0;
}