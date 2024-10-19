#include<stdio.h>

int main(){
    double temF;
    temF=100;
    printf("华氏温度 %5.2f 对应的摄氏度是 %5.2f\n",temF,5*(temF-32)/9);
    getchar();getchar();
    return 0;
}