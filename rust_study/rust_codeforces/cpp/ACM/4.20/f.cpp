/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\4.20\f.cpp
 *@date      2024/04/20 19:56:11
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n,ans = 0;
    cin >> n;
    auto low_bit = [](int x)->int {
        int p = x & -x, ans = 0;
        while(p)++ans, p >>= 1;
        return ans - 1;
        };
    vector<int>sg;
    vector<int>db;
    for(int i = 0;i < n;++i) {
        int x;
        cin >> x;
        if(x % 2)sg.emplace_back(x);
        else db.emplace_back(low_bit(x));
    }
    if(db.size() > sg.size()) {//偶数多
        sort(db.begin(), db.end());
        int t = db.size() - (n >> 1);
        for(int i = 0;i < t;++i)ans += db[i];
    }
    else ans += (sg.size() - (n >> 1));
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