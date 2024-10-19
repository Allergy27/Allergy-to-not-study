/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace DP\Direct_DP\P1216.cpp
 *@date      2024/03/28 08:21:08
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n;
    vector<int>qwq(n * (n + 1) / 2);

    for(i = 0;i < n;++i)
        for(j = 0;j <= i;++j)
            cin >> qwq[i * (i + 1) / 2 + j];

    for(i = n - 1;i >= 0;--i)
        for(j = i * (i + 1) / 2 - 1;j >= i * (i - 1) / 2;--j)
            qwq[j] += max(qwq[j + i], qwq[j + i + 1]);

    cout << qwq[0];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}