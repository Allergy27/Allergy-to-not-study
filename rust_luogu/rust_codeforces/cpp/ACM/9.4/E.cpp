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
int ma[100][100];
int bl[100][100];
unordered_map<pair<int, int>,int> blk;
set<pair<int, int>> s;
void dfs(int i, int j, int cnt) {
    if(cnt == n) {
        s.insert({ i, j });
        return;
    }
    if(a[cnt] == 'R') {
        dfs(i + 1, j, cnt + 1);
    }if(a[cnt] == 'L') {
        dfs(i - 1, j, cnt + 1);
    }if(a[cnt] == 'U') {
        dfs(i, j + 1, cnt + 1);
    }if(a[cnt] == 'D') {
        dfs(i, j - 1, cnt + 1);
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