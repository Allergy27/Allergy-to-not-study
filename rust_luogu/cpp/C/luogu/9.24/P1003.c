#include <stdio.h>

/*
这是洛谷的第3题,要求返回最上方的地毯是哪个,采用倒序枚举
*/

typedef struct carpetCoord{
    int xL;//左下角x
    int yL;
    int xR;//右上角x
    int yR;
} cC;

int n,x,y,xd,yd;
cC map[10001];//存放10000个毯子

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d%d%d",&map[i].xL,&map[i].yL,&xd,&yd);
        map[i].xR=map[i].xL+xd;//计算右上角坐标
        map[i].yR=map[i].yL+yd;
    }
    scanf("%d%d",&x,&y);
    for(int i=n;i>=1;--i){//从顶端开始查找,遇到满足的输出
        if(map[i].xR>=x && map[i].yR>=y && map[i].xL<=x && map[i].yL<=y){
            printf("%d",i);
            return 0;//找到合适的直接结束
        }
    }
    printf("-1");//没有合适的返回-1
    return 0;
}