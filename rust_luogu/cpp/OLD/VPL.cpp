#include <bits/stdc++.h>

using namespace std;
#define int long long
#define x first
#define y second
typedef pair<int, int> pii;

map<pii, int> mp;

void solve() {
    int n, bx, by;
    cin >> n >> bx >> by;
    cout << "Yes\n";
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> way;
    grid[bx - 1][by - 1] = 2;
    int i = 0, j = 0, t = 0, w = 0;
    vector<pair<int, int>>ct = { { 1, 1 }, { -1, 1 }, { -1, -1 }, { 1, -1 } };
    while(t != n - 1) {
        while(i != bx - 1 && j != by - 1) {
            ++t;int len = n - t;
            int l = ct[w].first, r = ct[w].second;
            vector<int> qwq = { i + 1, j + 1, len * l, len * r };
            i += l, j += r;
            way.emplace_back(qwq);
        }
        switch(w++) {
        case 0:i = n - 1;break;
        case 1:j = n - 1;break;
        case 2:i += t - n + 1;break;
        }
    }
    if(t == n - 1) {
        for(auto x : way)
            cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << '\n';
        return;
    }

}

signed main() {

    int _ = 1;
    while(_--)solve();

    return 0;
}