/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1152.cpp
 *@data      2024/01/17 21:41:03
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    bool flag = true;
    cin >> n;
    vector<int>qwq(n);
    vector<int>ans;
    for(auto &x : qwq)cin >> x;
    for(int i = 1;i < n;++i)ans.emplace_back(abs(qwq[i] - qwq[i - 1]));
    sort(ans.begin(), ans.end());
    for(int i = 1;i < n;++i) {
        if(i != ans[i - 1]) {
            flag = false;
            break;
        }
    }
    if(flag)cout << "Jolly";
    else cout << "Not jolly";
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}