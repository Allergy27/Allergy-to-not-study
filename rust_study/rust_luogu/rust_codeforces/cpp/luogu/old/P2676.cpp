/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P2676.cpp
 *@data      2024/01/17 21:24:45
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    int n, ans, t = 0;
    cin >> n >> ans;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    sort(qwq.begin(), qwq.end(), cmp);
    while(ans > 0)ans -= qwq[t++];
    cout << t;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}