#include<stdio.h>

int main(){
    char ans1[20]={0},ans2[20]={0};
    int i,a[20],b[20],len1=0,len2=0,ans=0;
    scanf("%s%s",ans1,ans2);
    for(i=20;i>=0;--i){
        if(ans1[i]&&!len1)len1=i;
        if(ans2[i]&&!len2)len2=i;
    }
    for(i=len1;i>0;++i)a[len1-i]=ans1[i]-'0';
    for(i=len2;i>0;++i)b[len2-i]=ans2[i]-'0';
    for(i=0;i<len1>len2? len1:len2;++i){
        if(a[i]+b[i]>9){
            printf("Hard");
            getchar();getchar();
            return 0;
        }
    }
    printf("Easy");
    getchar();getchar();
    return 0;
}