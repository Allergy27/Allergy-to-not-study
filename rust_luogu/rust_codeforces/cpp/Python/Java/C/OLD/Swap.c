#include<stdio.h>

int main(){
    int a=10,b=5;
    void swap(int*,int*);
    printf("%d %d\n",a,b);//a=10,b=5,输出10 5
    swap(&a,&b);//ab的值互换
    printf("%d %d\n",a,b);//a=5,b=10,输出5 10
    getchar();getchar();
    return 0;
}
void swap(int *m,int *n){*m^=*n;*n^=*m;*m^=*n;}//交换a,b的值，记得传入地址