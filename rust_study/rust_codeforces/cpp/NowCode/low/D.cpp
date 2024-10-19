/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace NowCode\low\D.cpp
 *@data      2023/11/22 20:29:26
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, Sum = 0, i, res = 0;
    cin >> n;
    vector<int>qwq(n);
    vector<int>prefix;
    for(auto &x : qwq) {
        cin >> x;
        Sum += x;
        prefix.emplace_back(Sum);//向前缀和数组中添加和
    }
    for(i = 0;i < n - 1;++i)res += (prefix[n - 1] - prefix[i]) == prefix[i];
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}