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
    int i = 0, j = 0, t = 0;
    while(i != bx - 1 && j != by - 1) {
        ++t;
        vector<int> qwq = { i + 1, j + 1, n - t, n - t };
        ++i, ++j;
        way.emplace_back(qwq);
    }
    if(t == n - 1) {
        for(auto x : way)
            cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << '\n';
        return;
    }
    i = n - 1;
    while(i != bx - 1 && j != by - 1) {
        ++t;
        vector<int> qwq = { i + 1, j + 1, t - n, n - t };
        --i, ++j;
        way.emplace_back(qwq);
    }
    if(t == n - 1) {
        for(auto x : way)
            cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << '\n';
        return;
    }
    j = n - 1;
    while(i != bx - 1 && j != by - 1) {
        ++t;
        vector<int> qwq = { i + 1, j + 1, t - n, t - n };
        --i, --j;
        way.emplace_back(qwq);
    }
    if(t == n - 1) {
        for(auto x : way)
            cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << '\n';
        return;
    }
    i += t - n;
    while(i != bx - 1 && j != by - 1) {
        ++t;
        vector<int> qwq = { i + 1, j + 1, n - t, t - n };
        ++i, --j;
        way.emplace_back(qwq);
    }
    if(t == n - 1) {
        for(auto x : way)
            cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << '\n';
        return;
    }
}

signed main() {

    int _ = 1;
    while(_--)
        solve();

    return 0;
}