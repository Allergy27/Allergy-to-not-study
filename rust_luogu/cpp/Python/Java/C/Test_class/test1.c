#include<stdio.h>

int main(){
    int num,class,age;
    printf("请输入你的学号：");
    scanf("%d",&num);
    printf("请输入你的班级：");
    scanf("%d",&class);
    printf("请输入你的年龄：");
    scanf("%d",&age);
    int nc=1,ca=1,numc=num,classc=class;
    while(numc>10000){
        numc/=10000;
        ++nc;
    }
    while(classc>10000){
        classc/=10000;
        ++ca;
    }
    printf("学号");
    while(nc--)printf("\t");
    printf("班级");
    while(ca--)printf("\t");
    printf("年龄\n");
    printf("%d\t%d\t%d",num,class,age);
    getchar();getchar();
    return 0;
}