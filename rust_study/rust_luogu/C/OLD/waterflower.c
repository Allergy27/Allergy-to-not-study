#include<stdio.h>
#include<math.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=pow(10,n-1);i<pow(10,n);++i){
        int numSum=0;j=i;
        while(j>0){
            numSum+=pow(j%10,n);
            j/=10;
        }
        if(numSum==i)printf("%d\n",numSum);
    }
    printf("The end");
    getchar();getchar();
    return 0;
}