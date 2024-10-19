/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1177.cpp
 *@data      2024/01/17 19:14:36
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, i;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    sort(qwq.begin(), qwq.end());
    for(i = 0;i < n;++i)cout << qwq[i] << (i == n - 1 ? '\n' : ' ');
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}