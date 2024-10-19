/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\4.20\c.cpp
 *@date      2024/04/20 19:05:11
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m,ans=0;
    cin >> n >> m;
    vector<string>qwq(n);
    for(int i = 0;i < n;++i)cin >> qwq[i];
    for(int i = 0;i < n - 1;++i)
        for(int j = 0;j < m - 1;++j)
            if((qwq[i][j] + qwq[i + 1][j] + qwq[i][j + 1] + qwq[i + 1][j + 1]) == 194)++ans;
    cout << ans;


}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}