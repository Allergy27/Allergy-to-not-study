#include<stdio.h>

int main(){
    int inputYear;
    int Judge(int);
    scanf("%d",&inputYear);

    //seprate the Year,Month,Day
    int countYear=inputYear/1000,countMonth=(inputYear/100)%100,countDay=inputYear%100;
    int MOUTH[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
    while(not(Judge(countYear*1000+countMonth*100+countDay))){
        int beforeCase[3]={0,0,0};
        if(countYear%100==0&&countYear%400==0||countYear%4==0)MOUTH[2]=29;
        else MOUTH[2]=28;
        if(countDay+1>MOUTH[countMonth]){
            countYear+=countMonth+1>12? 1:0;
            countMonth=countMonth+1>12? 1:countMonth+1;
            countDay=1;
        }
        else ++countDay;
    }
    printf("%d",countYear*1000+countMonth*100+countDay);
    int firstTwo=countYear/100;
    while((firstTwo%10)*10+firstTwo/10<13);//still writing
}

int Judge(int uniqueYear){
    int judgeYear=0;
    int usedYear=uniqueYear;
    for(int i=0;i<8;++i){
        judgeYear=judgeYear*10 + usedYear%10;
        usedYear/=10;
    }
    return judgeYear==usedYear? 1:0;
}