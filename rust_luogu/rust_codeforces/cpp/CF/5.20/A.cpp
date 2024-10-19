/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\5.20\A.cpp
 *@date      2024/05/20 22:32:27
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j, ans = 0;
    cin >> n >> m;
    if(m == 0) {
        cout << (n + 14) / 15 << '\n';
        return;
    }
    ans += m + 1 >> 1;
    int res = ans * 7 + (m & 1) * 4;
    if(n > res)ans += (n - res + 14) / 15;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}