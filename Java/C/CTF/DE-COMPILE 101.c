#include<stdio.h>
//6663496252449714278
//10197074784654686781
//10708900711610427813
char s[29];
int main(){
    scanf("%s",&s);
    for(int i=0;i<28;++i){
        s[i]+=3*i+1;
        s[i]^=i+1;
        printf("%s",s[i]);
    }
}