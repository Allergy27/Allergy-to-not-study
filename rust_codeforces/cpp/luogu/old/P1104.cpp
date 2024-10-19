/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1104.cpp
 *@data      2024/01/17 22:43:37
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct birthday {
    int id, y, m, d;
    string name;
    bool operator<(const birthday &other) const {
        if(y != other.y)return y < other.y;
        else {
            if(m != other.m)return m < other.m;
            else {
                if(d != other.d)return d < other.d;
                else return id > other.id;
            }
        }
    }
}qwq[127];

void solve() {
    int n;
    cin >> n;
    for(int i = 0;i < n;++i) {
        qwq[i].id = i;
        cin >> qwq[i].name >> qwq[i].y >> qwq[i].m >> qwq[i].d;
    }
    sort(qwq, qwq + n);
    for(int i = 0;i < n;++i)cout << qwq[i].name << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}