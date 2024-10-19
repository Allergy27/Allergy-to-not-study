#include<stdio.h>
#include<math.h>
int main(){
    long long int n,i,j,all[10]={0};
    scanf("%lld",&n);
    for(i=pow(10,n-1);i<pow(10,n);++i){
        int numSum=0;j=i;
        while(j>0){
            if(all[j%10]==0&&j%10!=0)all[j%10]=pow(j%10,n);
            numSum+=all[j%10];
            j/=10;
        }
        if(numSum==i)printf("%lld\n",numSum);
    }
    printf("The end");
    getchar();getchar();
    return 0;
}