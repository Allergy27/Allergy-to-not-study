/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P5143.cpp
 *@data      2024/01/17 22:17:04
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct posation {
    double x, y, z;
    bool operator<(const posation &other)const {
        return z < other.z;
    }
}qwq[52799];


void solve() {
    int n;
    cin >> n;
    memset(qwq, 0, sizeof(qwq));
    for(int i = 0;i < n;++i)cin >> qwq[i].x >> qwq[i].y >> qwq[i].z;
    sort(qwq, qwq + n);
    double ans = 0;
    for(int i = 1;i < n;++i)ans += sqrt((qwq[i - 1].x - qwq[i].x) * (qwq[i - 1].x - qwq[i].x)
        + (qwq[i - 1].y - qwq[i].y) * (qwq[i - 1].y - qwq[i].y)
        + (qwq[i - 1].z - qwq[i].z) * (qwq[i - 1].z - qwq[i].z));
    cout << setiosflags(ios::fixed) << setprecision(3) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}