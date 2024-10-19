/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\p1093.cpp
 *@data      2024/01/17 20:11:59
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct sdt {
    int num, cn, tot;
}qwq[527];

bool cmp(sdt a, sdt b) {
    if(a.tot != b.tot)return a.tot > b.tot;
    else {
        if(a.cn != b.cn)return a.cn > b.cn;
        else return a.num < b.num;
    }
}
void solve() {
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i) {
        int c, m, e;
        qwq[i].num = i;
        cin >> qwq[i].cn >> m >> e;
        qwq[i].tot = qwq[i].cn + m + e;
    }
    sort(qwq + 1, qwq + 1 + n, cmp);
    for(int i = 1;i <= 5;++i)cout << qwq[i].num << ' ' << qwq[i].tot << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}