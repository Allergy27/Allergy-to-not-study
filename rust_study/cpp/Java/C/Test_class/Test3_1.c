#include<stdio.h>

int main(){
    int i=3,j=2,a,b,c;
    a=(--i==j++)?--i:j++;
    b=i++;
    c=j;
    printf("a=%d, b=%d, c=%d\n",a,b,c);
    getchar();getchar();
    return 0;
}