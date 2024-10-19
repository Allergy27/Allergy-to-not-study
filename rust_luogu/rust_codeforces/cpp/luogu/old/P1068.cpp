/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1068.cpp
 *@data      2024/01/17 21:55:35
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct all_sc {
    int id, sc;
}qwq[5270];

bool cmp(all_sc a, all_sc b) {
    if(a.sc != b.sc)return a.sc > b.sc;
    else return a.id < b.id;
}

void solve() {
    int n, m, i, j;
    memset(qwq, 0, sizeof(qwq));
    cin >> n >> m;
    m = floor(m * 1.5);
    for(int i = 0;i < n;++i)cin >> qwq[i].id >> qwq[i].sc;
    sort(qwq, qwq + n, cmp);
    while(m < n && qwq[m - 1].sc == qwq[m].sc)++m;
    cout << qwq[m - 1].sc << ' ' << m << '\n';
    for(int i = 0;i < m;++i)cout << qwq[i].id << ' ' << qwq[i].sc << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}