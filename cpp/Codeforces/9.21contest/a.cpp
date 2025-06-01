/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\9.21contest\a.cpp
 *@date      2024/09/21 22:46:17
 */
#include <bits/stdc++.h>
// #define int long long

using namespace std;
using ll = long long;
int inf = 0x3f3f3f3f;

void solve() {
    int n, k, get = 0, ans = 0;
    cin >> n >> k;
    vector<int> qwq(n);
    for (auto &x : qwq) {
        cin >> x;
        if (x >= k)
            get += x;
        else if (x == 0) {
            if (get > 0) ++ans, --get;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}