#include<stdio.h>

int main(){
    int a=3,b=3;
    printf("%d %d\n",++a,b--);
    a=b=3;
    a+=a++;
    b+=++b;
    printf("%d %d\n",a,b);
    getchar();getchar();
    return 0;
}