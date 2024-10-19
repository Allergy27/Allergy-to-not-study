#include<stdio.h>
/*想到更好的思路了,比赛结束改一下*/
int main(){
    int n,i,max=0,a[27]={0},b[27]={0};
    int get(int);
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
        b[i]=get(a[i]);
    }
    for(i=0;i<n;++i){
        for(int j=0;j<n;++j)max=b[j]>b[max]? j:max;
        printf("%d",a[max]);
        b[max]=0;
    }
    getchar();getchar();
    return 0;
}

int get(int num){
    int qwq=num;
    while(qwq>9)qwq/=10;
    return qwq;
}