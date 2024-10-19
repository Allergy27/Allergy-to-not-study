/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\p1271.cpp
 *@data      2024/01/17 19:06:01
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>qwq(m);
    for(int i = 0;i < m;++i)cin >> qwq[i];
    sort(qwq.begin(), qwq.end());
    for(auto x : qwq)cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}