#include<stdio.h>
char ans[20][10];
int main(){
    int i,n,j,check(char a[],char b[]),max_all[20]={0};//各种变量
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%s",ans[i]);
    for(i=0;i<n;++i){
        int max=0;
        while(max_all[max]==1)++max;//如果这个值已经被标记为最大值了就往后走
        for(j=0;j<n;++j){//选择排序
            if(max_all[j]==1)continue;//这个是最大值的话就不取了
            if(check(ans[j],ans[max]))max=j;//取最大值
        }
        max_all[max]=1;//标记为最大值
        printf("%s",ans[max]);
    }
    getchar();getchar();
    return 0;
}
int check(char a[],char b[]){//比较字符串大小
    int k=0;
    while (a[k]==b[k]&&(a[k]!=0||b[k]!=0))++k;
    int m=a[k]==0? a[k-1]:a[k];
    int n=b[k]==0? b[k-1]:b[k];
    return m>n;
}