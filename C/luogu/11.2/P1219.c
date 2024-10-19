#include<stdio.h>
#define maxN 15
int Broad[maxN],ES[maxN*2],WN[2*maxN+1],UN[maxN],sum=0;

int main(){
    int n;scanf("%d",&n);
    void dfs(int,int);
    dfs(0,n);
    printf("%d",sum);
    getchar();getchar();
    return 0;
}
void dfs(int i,int N){
    int j;
    for(j=0;j<N;++j){
        if((!Broad[j])&&(!ES[i-j+N-1])&&(!WN[i+j])){
            UN[i]=j+1;
            Broad[j]=1;//摆了皇后
            ES[i-j+N-1]=1;//东南对角线
            WN[i+j]=1;//西北对角线
            if(i==N-1){
                ++sum;
                if(sum <=3){
                    for(int t=0;t<N;++t)printf("%d ",UN[t]);
                    printf("\n");
                }
            }
            else dfs(i+1,N);
            Broad[j]=0;
            ES[i-j+N-1]=0;
            WN[i+j]=0;
        }
    }
}