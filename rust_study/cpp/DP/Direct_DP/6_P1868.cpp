/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace DP\Direct_DP\6_P1868.cpp
 *@date      2024/03/28 19:17:44
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
vector<int>qwq[3000010];
void solve() {
    int n, m, i, mx = 0, x, y;
    cin >> n;

    for(i = 0;i < n;++i) {
        cin >> x >> y;
        mx = max(mx, y);
        qwq[y].emplace_back(x - 1);
    }
    vector<int>ans(mx + 1);
    for(i = 1;i <= mx;++i) {
        ans[i] = ans[i - 1];
        if(!qwq[i].empty())
            for(auto x : qwq[i])ans[i] = max(ans[i], ans[x] + i - x);
    }
    cout << ans[mx];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}