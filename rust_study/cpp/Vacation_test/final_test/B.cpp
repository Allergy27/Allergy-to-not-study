/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Vacation_test\final_test\B.cpp
 *@date      2024/08/20 16:14:49
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    if(x * y < 0 || abs(x) < abs(y) && x * y > 0) {//如果墙没堵住，就不用管锤子的事了，直接给出答案
        cout << abs(x);
        return;
    }
    if(abs(y) < abs(z) && y * z > 0) {//如果锤子在墙后,就不用考虑了，肯定拿不到
        cout << -1;
        return;
    }
    cout << abs(x - z) + abs(z);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}