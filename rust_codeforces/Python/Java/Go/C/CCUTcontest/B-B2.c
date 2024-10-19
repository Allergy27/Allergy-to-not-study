#include<stdio.h>
long long m(long long n){
    if(n==1)return 0;
    else if(n%2==0)return 1+m(n/2);
    else if(n%3==0)return 2+m(n/3);
    else if(n%5==0)return 3+m(n/5);
    else return -999;
}
int main(){
    int q,i;
    scanf("%d",&q);
    for(i=0;i<q;++i){
        long long n;
        scanf("%lld",&n);
        printf("%d\n",m(n)>=0?m(n):-1);
    }
    return 0;
}