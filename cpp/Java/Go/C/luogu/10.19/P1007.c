#include<stdio.h>

int main(){
    int L,N,i,min=0,max=0,wB;
    scanf("%d",&L);
    scanf("%d",&N);
    for(i=0;i<N;++i){
        scanf("%d",&wB);//下面用了条件表达式，代码是不是很简洁qwq
        min=((wB<L+1-wB)? wB:L+1-wB)>min? ((wB<L+1-wB)? wB:L+1-wB):min;//最小值的最大值
        max=((wB>L+1-wB)? wB:L+1-wB)>max? ((wB>L+1-wB)? wB:L+1-wB):max;
    }
    printf("%d %d",min,max);
    getchar();getchar();
    return 0;
}