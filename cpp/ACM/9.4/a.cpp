/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\9.4\a.cpp
 *@date      2024/09/04 12:56:49
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
string a;

int n, m, i, j;
int ma[1000][100];
int bl[1000][100];
set<pair<int, int>> s;
void dfs(int i, int j, int cnt) {
    if(cnt == n) {
        s.insert({ i, j });
        return;
    }
        s.insert({ i, j });
    ma[i + 49][j + 49] = 1;
    int ni, nj;
    if(a[cnt] == 'R') {
        ni = i + 1;
        nj = j;
    }if(a[cnt] == 'L') {
        ni = i - 1;
        nj = j;
    }if(a[cnt] == 'U') {
        ni = i;
        nj = j + 1;
    }if(a[cnt] == 'D') {
        ni = i;
        nj = j - 1;
    }
    if(bl[ni + 49][nj + 49]) dfs(i, j, cnt + 1);
    else {
        ma[ni + 49][nj+49] = 1;
        dfs(ni, nj, cnt + 1);
        ma[ni + 49][nj + 49] = 0;

        bl[ni + 49][nj + 49] = 1;
        dfs(i, j, cnt + 1);
        bl[ni + 49][nj + 49] = 0;
    }
}
void solve() {
    cin >> n;
    cin >> a;
    dfs(0, 0, 0);
    for(auto [i, j] : s) {
        cout << i << ' ' << j << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}