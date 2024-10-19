/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.19\a.cpp
 *@date      2024/03/19 18:51:24
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i < n.size() - 1;++i)
        if(n[i] == n[i + 1] || n[i + 1] == '?' || n[i] == '?') {
            ++ans;++i;
        }
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