#include<stdio.h>

int main(){
    int m,n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        int all[4]={0},flag=0;char ans[55]={0};
        scanf("%s",ans);
        for(j=0;j<18;++j){
            //判断字符长度
            if(ans[j]==0&&j>7)break;
            else if(j>15||(ans[j]==0&&j<=7)){flag=1;break;}
            //字符
            if((ans[j]>='0'&&ans[j]<='9')&&all[0]==0)all[0]=1;
            if((ans[j]>='a'&&ans[j]<='z')&&all[1]==0)all[1]=1;
            if((ans[j]>='A'&&ans[j]<='Z')&&all[2]==0)all[2]=1;
            if((ans[j]==33||ans[j]==35||ans[j]==36||ans[j]==37||ans[j]==94||ans[j]==126||ans[j]==64)&&all[3]==0)all[3]=1;
        }
        if(flag==0&&(all[0]+all[1]+all[2]+all[3])>=3)printf("YES\n");
        else printf("NO\n");
    }
    getchar();getchar();
    return 0;
}