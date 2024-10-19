#include<stdio.h>

int main(){
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    for(i=0;i<n;++i){
        for(j=0;j<m;++j)printf("*");
        printf("\n");
    }
    getchar();getchar();
    return 0;
}