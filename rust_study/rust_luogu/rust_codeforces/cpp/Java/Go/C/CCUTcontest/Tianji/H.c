#include<stdio.h>
char all[102][102];int ans[102][102];
void check(int,int,int);
int main(){
    int m,n,p,q;
    scanf("%d%d",&n,&m);
    getchar();//读掉换行符
    for(p=1;p<=n;++p){
        for(q=1;q<=m;++q)scanf("%c",&all[p][q]);
        getchar();//读掉换行符
    }
    int qvq=0;
    for(p=1;p<=n;++p){
        for(q=1;q<=m;++q){
            if(all[p][q]=='W'&&ans[p][q]==0){
                check(p,q,qvq);++qvq;
            }
            
        }
    }
    /*
    for(p=1;p<=n;++p){
        for(q=1;q<=m;++q)printf("%d ",ans[p][q]);//qvq+=check(1,1,qvq);
        printf("\n");
    }
    */
    printf("%d",qvq);
    getchar();getchar();
    return 0;
}
void check(int i,int j,int qwq){
    if(all[i][j]=='.')
        return ;
    if(all[i][j]=='W'&&ans[i][j]==0){
        ans[i][j]=1;
        check(i-1,j-1,qwq);
        check(i-1,j,qwq);
        check(i,j-1,qwq);
        check(i,j+1,qwq);
        check(i+1,j+1,qwq);
        check(i+1,j,qwq);
        check(i-1,j+1,qwq);
        check(i+1,j-1,qwq);
    }
}