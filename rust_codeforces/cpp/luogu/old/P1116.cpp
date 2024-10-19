/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1116.cpp
 *@data      2024/01/17 21:37:06
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    for(int i = 0;i < n;++i)
        for(int j = 0;j < i;++j)
            if(qwq[i] < qwq[j])++ans;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}