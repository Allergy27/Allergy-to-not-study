#include<stdio.h>

int main(){
    int n;long long m;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int flag=0;
        scanf("%lld",&m);
        while(m%5==0){
            m=m/5*4;
            ++flag;
        }
        while(m%3==0){
            m=m/3*2;
            ++flag;
        }
        while(m%2==0){
            m>>=1;
            ++flag;
        }
        if(m!=1){
            flag=-1;
        }
        printf("%d\n",flag);
    }
    getchar();getchar();
    return 0;
}