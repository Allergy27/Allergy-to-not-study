#include<stdio.h>

int main(){
    int n,width,lenth;
    scanf("%d",&n);
    for(int num=0;num<n;++num){//处理第num组数据
        int answer=0;
        char ans[11]={0};
        for(lenth=0;lenth<10;++lenth){//行数
            scanf("%s",ans);
            for(width=0;width<10;++width)//列数
                if(ans[width]=='X')//中箭
                    for(int k=5;k<10;++k)//计算环数和得分
                        if(((lenth==k||lenth==9-k)&&(width>=9-k)&&(width<=k))//判断横行
                            ||((width==k||width==9-k)&&(lenth>=9-k)&&(lenth<=k)))//判断纵行
                                answer+=10-k;//计算得分
        }
        printf("%d\n",answer);//输出结果
    }
    getchar();getchar();
    return 0;
}