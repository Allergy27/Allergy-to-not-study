/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\11.20\1899C.cpp
 *@data      2023/11/20 17:48:20
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    int ans = qwq[0];
    int neg = min(0, qwq[0]), sum = qwq[0];
    for(i = 1; i < n; ++i) {
        if((qwq[i - 1] + qwq[i]) % 2 == 0) {
            neg = 0;
            sum = 0;
        }
        sum += qwq[i];
        ans = max(ans, sum - neg);//留不留下前面的负数
        neg = min(neg, sum);
    }
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