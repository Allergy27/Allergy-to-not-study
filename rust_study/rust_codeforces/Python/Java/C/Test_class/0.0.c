#include<stdio.h>

int main(){
    double x=3.4, y=7.8;
    int a,b,c,d;
    a=x+y;
    b=(int)(x+y);
    c=(int)x+y;
    d=x+(int)y;
    printf("%f%f\n",x,y);
    printf("a=%d,b=%d,c=%d,d=%d",a,b,c,d);
    getchar();getchar();
    return 0;
}