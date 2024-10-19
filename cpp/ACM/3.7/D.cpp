/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.7\D.cpp
 *@date      2024/03/07 19:50:47
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n >> m;
    vector<int>qwq(n);
    vector<int>cnt(m);
    for(auto &x : qwq)cin >> x;
    for(auto &x : cnt)cin >> x;
    for(auto j:cnt) {
        int k = lower_bound(qwq.begin(), qwq.end(), j)-qwq.begin();
        cout << k << ' ';
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