/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace DP\Direct_DP\3_P1091.cpp
 *@date      2024/03/28 09:25:48
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j, ans = -INT_MAX;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;

    auto lis = [](vector<int> qwq) -> vector<int> {
        vector<int>x;
        vector<int>ans;
        for(auto y : qwq) {
            if(x.empty() || x.end()[-1] < y)x.emplace_back(y);
            else x[distance(x.begin(), lower_bound(x.begin(), x.end(), y))] = y;
            ans.emplace_back(x.size());
        }
        return ans;
        };

    vector<int>res1 = lis(qwq);
    reverse(qwq.begin(), qwq.end());
    vector<int>res2 = lis(qwq);
    for(i = 0;i < n;++i)ans = max(res1[i] + res2[n - i - 1], ans);
    cout << n + 1 - ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}