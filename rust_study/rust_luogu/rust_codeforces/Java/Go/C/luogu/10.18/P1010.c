#include<stdio.h>
#include<math.h>
int main(){
    int n;void check(int);
    scanf("%d",&n);
    check(n);
    getchar();getchar();
    return 0;
}
void check(int x){
    for(int i=14;i>=0;i--){//从最大的开始分解成小的
        if(pow(2,i)<=x){//暴力枚举,开始拆解
            if(i==1)printf("2");//两种不能拆了的情况
            else if(i==0) printf("2(0)");
            else{//还能接着拆的情况
                printf("2(");check(i);printf(")");
            }
            x-=pow(2,i);
            if(x!=0) printf("+");//连接
        }
    }
}