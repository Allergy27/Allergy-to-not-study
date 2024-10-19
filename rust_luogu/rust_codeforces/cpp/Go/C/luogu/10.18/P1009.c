#include<stdio.h>
/*比较简洁，超来的，之后用c++重写一遍（虽然之前Python做出来了）*/
int main(){
    int A[105]={0},B[105]={0},n,i,j;
    scanf("%d",&n);
    A[0]=B[0]=1;
    for(i=2;i<=n;++i){
        for(j=0;j<100;++j)B[j]*=i;
        for(j=0;j<100;++j){
            if(B[j]>9){
                B[j+1]+=B[j]/10;
                B[j]%=10;
            }
        }
        for(j=0;j<100;++j){
            A[j]+=B[j];
            if(A[j]>9){
                A[j+1]+=A[j]/10;
                A[j]%=10;
            }
        }
    }
    for(i=100;i>=0&&A[i]==0;--i);
    for(j=i;j>=0;--j)printf("%d",A[j]);
    return 0;
}