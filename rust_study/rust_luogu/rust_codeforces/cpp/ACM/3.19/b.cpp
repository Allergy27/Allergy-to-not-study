/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.19\b.cpp
 *@date      2024/03/19 19:12:17
 */
#include<bits/stdc++.h>
#define int long long

using namespace std;

int victory(vector<int>a, vector<int>b, vector<int>c, int n) {
    vector<int> qwq;
    for(int i = 0;i < n;++i)qwq.emplace_back(a[i] - b[i] - c[i]);
    sort(qwq.begin(), qwq.end(), greater<>());
    lnt sum = 0;
    for(int i = 0;i < n;++i) {
        sum += qwq[i];
        if(qwq[i + 1] <= 0)return i;
    }
    return n;
}

void solve() {
    int n, m, i, j, x = 0, y = 0, z = 0, t;
    cin >> n;
    vector<int>g1(n); //魏国
    vector<int>g2(n); //蜀国
    vector<int>g3(n); //吴国
    for(auto &x : g1)cin >> x;
    for(auto &x : g2)cin >> x;
    for(auto &x : g3)cin >> x;
    x = victory(g1, g2, g3, n);
    y = victory(g2, g1, g3, n);
    z = victory(g3, g1, g2, n);
    int ans = max({ x, y, z });
    cout << (ans == 0 ? -1 : ans);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}