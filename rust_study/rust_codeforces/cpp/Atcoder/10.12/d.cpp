// // Copyright 2024 Allergy
// /* @author    Allergy
//  * @email     Allergy527@gmail.com
//  * @workspace Atcoder\10.12\d.cpp
//  * @date      2024/10/12 20:34:56
//  */
// #include<bits/stdc++.h>
// #define lowbit(x) ((x)&(-(x)))
// #define int int64_t

// using namespace std;  // NOLINT
// using ll = int64_t;
// int inf = 0x3f3f3f3f;
// ll ll_inf = 0x3f3f3f3f3f3f3f3f;
// #define ln '\n'
// void solve() {
//     string s;
//     cin >> s;
//     map < char, vector < int > > mp;
//     for (int i = 0; i < s.size(); i++) {
//         mp[s[i]].push_back(i);
//     }
//     int ans = 0;
//     for (auto [x, y] : mp) {
//         int cnt = -1;
//         int def = 0;
//         for (auto z : y) {
//             ++cnt;
//             ans += z - cnt -1;
//         }
//     }
//     cout << ans << ln;
// }

// signed main() {
//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//     int t = 1;
//     // cin >> t;j
//     while (t--) solve();
//     cin >> t;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int>> mem(300000);
bool judge[300000];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        mem[a].push_back(b);
    }
    queue<int> q;

    q.push(1);
    judge[1] = true;
    long long ans = 0;
    while (q.size() != 0) {
        long long x = q.front();
        q.pop();
        if (x == M) {
            cout << ans << '\n';
            return 0;
        }
        for (int i = 0; i < mem[x].size(); i++) {

            if (judge[mem[x][i]]) continue;
            q.push(mem[x][i]);
        }
        ans++;
    }
    cout << 0 << endl;
    return 0;
}