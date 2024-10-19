/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\4.10\6.cpp
 *@date      2024/04/10 13:00:17
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
int qwq[57][57], qvq[57][57];
pair<int, int>way[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
void solve() {
    int n, m, i, j;
    cin >> n >> m;
    for(i = 1;i <= n;++i) {
        string str;
        cin >> str;
        for(j = 1;j <= m;++j)qwq[i][j] = str[j - 1] ^ 48;
    }
    auto bfs = [&](auto self, int x, int y, int sgn)->int {
        if(qwq[x][y] == 1) {
            qwq[x][y] = sgn;
            for(auto &item : way)self(self, x + item.first, y + item.second, sgn);
        }
        return 0;
        };
    auto Bfs = [&](auto self, int x, int y, bool XD)->bool {
        if(x == 0 || x == n + 1 || y == 0 || y == m + 1)return true;
        if(XD || !qvq[x][y] && !qwq[x][y]) {
            qvq[x][y] = 1;
            for(int p = -1;p <= 1;++p)
                for(int q = -1;q <= 1;++q)
                    if(!qwq[x + p][y + q] && self(self, x + p, y + q, false))return true;
        }
        return false;
        };

    int f = 1, ans = 0;
    vector<int>check(2501);
    for(i = 1;i <= n;++i)
        for(j = 1;j <= m;++j) {
            if(qwq[i][j] == 1)bfs(bfs, i, j, ++f);
            memset(qvq, 0, sizeof(qvq));
            if(qwq[i][j] > 1 && !check[qwq[i][j]] && Bfs(Bfs, i, j, true)) {
                ++ans;
                check[qwq[i][j]] = 1;
            }
        }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}
