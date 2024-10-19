#include<stdio.h>

typedef struct date_year {
    int year;
    int month;
    int day;
}date;


int main() {
    int day_y[12] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
    int day_n[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
    for(int i = 1;i < 12;++i)day_y[i] += day_y[i - 1];
    for(int i = 1;i < 12;++i)day_n[i] += day_n[i - 1];
    date qwq;
    scanf("%d%d%d", &qwq.year, &qwq.month, &qwq.day);
    printf("%d", qwq.year % 400 == 0 || qwq.year % 4 == 0 && qwq.year % 100 != 0 ? qwq.day + day_y[qwq.month - 1] : qwq.day + day_n[qwq.month - 1]);
    getchar();getchar();
    return 0;
}