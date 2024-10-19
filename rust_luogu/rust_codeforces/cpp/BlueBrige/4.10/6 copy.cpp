/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\4.10\6.cpp
 *@date      2024/04/10 13:00:17
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
void bfs(vector<vector<int>> &qwq, int x, int y, int sgn) {
    if(qwq[x][y] == 1) {
        qwq[x][y] = sgn;
        bfs(qwq, x == n ? 1 : x + 1, y, sgn);
        bfs(qwq, x, y == m ? 1 : y + 1, sgn);
        bfs(qwq, x == 1 ? n : x - 1, y, sgn);
        bfs(qwq, x, y == 1 ? m : y - 1, sgn);
    }
}
bool Bfs(vector<vector<int>> &qvq, vector<vector<int>>qwq, int x, int y, bool XD) {
    bool flag = false;
    if(x == 0 || x == n + 1 || y == 0 || y == m + 1)return true;
    if(XD || !qvq[x][y] && !qwq[x][y]) {
        qvq[x][y] = 1;
        for(int p = -1;p <= 1;++p)
            for(int q = -1;q <= 1;++q)
                if(!qwq[x + p][y + q])flag |= Bfs(qvq, qwq, x + p, y + q, false);
        qvq[x][y] = 0;
    }
    return flag;
}
void solve() {
    int i, j;
    cin >> n >> m;
    vector<vector<int>>qwq(n + 2, vector<int>(m + 2));
    vector<vector<int>>qvq(n + 2, vector<int>(m + 2));
    for(i = 1;i <= n;++i) {
        string str;
        cin >> str;
        for(j = 1;j <= m;++j)qwq[i][j] = (int) (str[j - 1] - '0');
    }
    int f = 1, ans = 0;
    vector<int>check(2501);
    for(i = 1;i <= n;++i)
        for(j = 1;j <= m;++j) {
            if(qwq[i][j] == 1)bfs(qwq, i, j, ++f);
            if(qwq[i][j] > 1 && !check[qwq[i][j]] && Bfs(qvq,qwq, i, j, true)) {
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