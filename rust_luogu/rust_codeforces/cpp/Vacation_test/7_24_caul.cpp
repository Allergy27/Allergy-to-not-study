/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Vacation_test\7_24_get.cpp
 *@date      2024/07/24 15:46:20
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int a, c;
    char b;
    scanf("%d %c %d", &a, &b, &c);
    switch(b) {
    case '+':
        printf("%d", a + c);
        break;
    case '-':
        printf("%d", a - c);
        break;
    case '*':
        printf("%d", a * c);
        break;
    case '/':
        printf("%.2lf", (double) a / c);
        break;
    default:
        break;
    }
    return 0;
}