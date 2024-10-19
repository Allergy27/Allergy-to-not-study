/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\4.20\h.cpp
 *@date      2024/04/20 18:30:54
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    int n, m, i, j;
    cin >> n >> m;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    sort(qwq.begin(), qwq.end(), cmp);
    for(i = 1;i < n;++i)qwq[i] += qwq[i - 1];
    while(m--) {
        cin >> j;
        if(qwq[n - 1] < j)cout << "-1\n";
        else cout << lower_bound(qwq.begin(), qwq.end(), j) - qwq.begin() + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}