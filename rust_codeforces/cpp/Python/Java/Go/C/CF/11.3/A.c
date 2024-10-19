#include<stdio.h>

int main(){
    int i,n,a,b,c;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d%d%d",&a,&b,&c);
        if(a>=b)printf("%d\n",a);
        else printf("%d\n",a+c>=b? b:b+b-c-a);
    }
    getchar();getchar();
    return 0;
}