#include<stdio.h>

int main(){
    int n,a,b,i;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        if(a>1){printf("%d\n",1);}
        else {printf("%d\n",a+b);}
    }
    return 0;
}