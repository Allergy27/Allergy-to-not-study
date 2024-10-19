/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.7\C.cpp
 *@date      2024/03/07 19:18:08
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, ans = 0, i, j;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    sort(qwq.begin(), qwq.end());
    for(i = 0;;++i)
        if(i == n-1 || qwq[i] > 0) {
            j = i;
            break;
        }
    for(i = 0;qwq[i]<0&&i <= j;++i)qwq[i] = -1 * qwq[i];
    for(auto x : qwq)ans += x;
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}