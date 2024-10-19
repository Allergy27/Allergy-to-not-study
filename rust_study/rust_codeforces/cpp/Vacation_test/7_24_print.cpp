/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Vacation_test\7_24.cpp
 *@date      2024/07/24 15:34:10
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    for(int i = 1; i <= 9;++i) {
        for(int j = 1;j <= i;++j)printf("%d*%d=%-2d ",j,i,i*j);
        cout << '\n';
    }
    return 0;
}