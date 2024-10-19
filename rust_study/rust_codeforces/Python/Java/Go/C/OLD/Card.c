#include<stdio.h>

int main(){
    int allCard[10];//record the number of cards ranging from 1 to 9
    for(int i=0;i<10;++i)allCard[i]=2019;//Initialize the list
    int ansNum=0;//record the number judging
    int flag=1;//when to jump out
    while(flag){
        ++ansNum;//start from 1
        int ansCopy=ansNum;//Creat a copy of the number
        while(ansCopy!=0){
            if(allCard[ansCopy%10]>0)--allCard[ansCopy%10];//The cards are used
            else{
                flag=0;
                break;//Cards aren't enough,so break
            }
            ansCopy/=10;
        }
    }
    printf("%d",ansNum);
    getchar();//I'd like show the answer rather than count the consequence
    return 0;
}