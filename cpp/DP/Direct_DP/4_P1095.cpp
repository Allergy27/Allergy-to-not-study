/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace DP\Direct_DP\4_P1095.cpp
 *@date      2024/03/28 09:55:00
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int m, s, t, ans1 = 0, ans2 = 0;
    cin >> m >> s >> t;
    for(int i = 1; i <= t; ++i) {
        ans1 += 17;
        if(m >= 10)ans2 += 60, m -= 10;
        else m += 4;
        ans1 = max(ans1,ans2);
        if(ans1 > s) {
            cout << "Yes\n" << i << '\n';
            return;
        }
    }
    cout << "No\n" << ans1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}