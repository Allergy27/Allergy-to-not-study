/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.11\C.cpp
 *@date      2024/03/11 19:00:45
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct Int {
    int first, second;
};

bool cmp(Int a, Int b) {
    if(a.first != b.first)return a.first < b.first;
    else return a.second > b.second;
}
void solve() {
    int n, m, i, j;
    cin >> n;
    vector<Int>qwq(n);

    for(i = 0;i < n;++i) {
        string k;
        cin >> k;
        qwq[i] = { 0, i + 1 };
        for(auto x : k) if(x == 'o')++qwq[i].first;
    }
    sort(qwq.begin(), qwq.end(), cmp);
    for(i = n - 1;i >= 0;--i)cout << qwq[i].second << ' ';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}