/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.27\A.cpp
 *@data      2024/02/27 18:48:12
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, f = -1;
    cin >> n >> m;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    for(int i = 1; i < n;++i)if(qwq[i] - qwq[i - 1] <= m && !(f + 1))f = qwq[i];
    cout << f;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}