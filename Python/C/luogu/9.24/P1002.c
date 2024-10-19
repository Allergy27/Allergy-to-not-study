#include <stdio.h>
/*
这是洛谷的第2题,要求返回卒到对应点的方法数,采用动态规划
*/

//马的控制点
const int houseX[]={-2, -1, 1, 2,  2,  1, -1, -2};
const int houseY[]={ 1,  2, 2, 1, -1, -2, -2, -1};

long long chessBoard[30][30];//棋盘
_Bool     checkBoard[30][30];//是否被马控制

int main(){
    int bX,bY,hX,hY;
    scanf("%d%d%d%d",&bX,&bY,&hX,&hY);
    bX+=2;bY+=2;hX+=2;hY+=2;
    
    chessBoard[2][1]=1;//棋盘外进行初始化,实现路径数求值
    checkBoard[hY][hX]=1;//马的位置
    
    for(int i=0;i<8;++i)checkBoard[hY+houseY[i]][hX+houseX[i]]=1;//马的控制点
    for(int m=2;m<=bY;++m){
        for(int n=2;n<=bX;++n){
            if(checkBoard[m][n])continue;//是马的控制点则继续
            chessBoard[m][n]=chessBoard[m-1][n]+chessBoard[m][n-1];//不是的话就进行相加
        }
    }
    printf("%lld",chessBoard[bY][bX]);
    return 0;
}