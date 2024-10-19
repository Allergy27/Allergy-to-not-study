#include<stdio.h>


double Plus(double, double);

int main() {
    //for(int i = 1;i <= 5;++i)
    printf("%lf\n", Plus(0.1, 0.0001));
    getchar();getchar();
    return 0;
}
double Plus(double n, double m) {
    double y = 1.0;
    int week = 1;
    for(int i = 1;i <= 365;++i) {
        if(week != 0)y *= (1 + n);
        else y *= (1 - m);
        week = (week + 1) % 7;
    }
    return y;
}