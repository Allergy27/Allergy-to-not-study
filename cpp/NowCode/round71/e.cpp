// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round71\e.cpp
 * @date      2024/12/08 20:29:17
 */
#include <bits/stdc++.h>
#define ln '\n'
#define int int64_t

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> a;
    vector<int> lengths;
    for (int i = 0; i < n; ++i) {
        int l, cnt;
        cin >> l >> cnt;
        a[l] += cnt;
        lengths.push_back(l);
    }
    sort(lengths.begin(), lengths.end());
    lengths.erase(unique(lengths.begin(), lengths.end()), lengths.end());

    auto heron = [](double a, double b, double c) {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    };

    double ans = -1;
    for (auto l : lengths) {
        int cnt = a[l];
        if (cnt >= 2) {
            // 尝试等边三角形
            if (cnt >= 3) {
                ans = max(ans, heron(l, l, l));
            }
            // 寻找可作为底边的长度
            auto it = upper_bound(lengths.begin(), lengths.end(), l * 2);
            if (it != lengths.begin()) {
                --it;
                if (*it == l && it != lengths.begin())
                    --it;
                else if (*it == l && it == lengths.begin())
                    continue;
                ans = max(ans, heron(l, l, *it));
            }
        }
    }
    if (ans == -1)
        cout << -1 << ln;
    else
        cout << fixed << setprecision(10) << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}