/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1060.cpp
 *@date      2024/04/09 19:05:41
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j, a, b;
    cin >> n >> m;
    vector<int>qwq(n + 1);
    for(i = 0;i < m;++i) {
        cin >> a >> b;
        for(j = n;j >= a;--j)
            qwq[j] = max(qwq[j], qwq[j - a] + a * b);
    }
    cout << qwq[n];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}