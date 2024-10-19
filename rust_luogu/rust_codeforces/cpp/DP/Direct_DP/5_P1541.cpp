/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace DP\Direct_DP\5_P1541.cpp
 *@date      2024/03/28 15:44:48
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int ans[45][45][45];

void solve() {
    int n, m, i, j;
    cin >> n >> m;

    vector<int>qwq(n);
    vector<int>opr(4);
    for(auto &x : qwq)cin >> x;
    for(i = 0;i < m;++i)cin >> j, ++opr[j - 1];

    for(int a = 0;a <= opr[0];++a)
        for(int b = 0;b <= opr[1];++b)
            for(int c = 0;c <= opr[2];++c)
                for(int d = 0;d <= opr[3];++d) {
                    if(b)ans[b][c][d] = max(ans[b - 1][c][d], ans[b][c][d]);
                    if(c)ans[b][c][d] = max(ans[b][c - 1][d], ans[b][c][d]);
                    if(d)ans[b][c][d] = max(ans[b][c][d - 1], ans[b][c][d]);
                    ans[b][c][d] += qwq[a + b * 2 + c * 3 + d * 4]; //第一维会在最外圈体现，不用管
                }
    cout << ans[opr[1]][opr[2]][opr[3]];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}