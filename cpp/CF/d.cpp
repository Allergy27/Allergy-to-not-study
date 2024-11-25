// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\d.cpp
 * @date      2024/11/24 01:05:37
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for (auto &x : arr)
        cin >> x;
    // 按降序排序S以获得字典序最大的数组
    sort(arr.begin(), arr.end(), greater<int>());
    // 初始化结果数组
    vector<int> qwq(n, -1);
    bool flag = true;
    // 预处理每个位置i的所有约数d
    vector<vector<int>> div(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            div[j].push_back(i);
    for (int i = 1; i <= n; i++) {
        for (auto x : arr) {
            bool valid = true;
            // 检查所有d = gcd(i,j)的情况
            for (auto d : div[i]) {
                if (d < i) {
                    if (qwq[d - 1] != -1 && __gcd(x, qwq[d - 1]) == qwq[d - 1]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) {
                qwq[i - 1] = x;
                break;
            }
        }
        if (qwq[i - 1] == -1) {
            flag = false;
            break;
        }
    }
    if (flag) {
        for (auto num : qwq)
            cout << num << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}