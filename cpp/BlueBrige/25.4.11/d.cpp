// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.11\d.cpp
 * @date      2025/04/11 13:56:46
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    auto bin_div = [](std::vector<int> &a) {
        int n = a.size();
        int tmp = 0;
        for (int i = n - 1; i >= 0; --i) {
            int pre = tmp;
            tmp = a[i] & 1;
            if (i == n - 1 && a[i] == 1 || a[i] == 0)
                a.pop_back();
            else
                a[i] = (pre * 10 + a[i]) / 2;
        }
        return tmp;
    };
    auto bin_mul = [](std::vector<int> &a) {
        int n = a.size();
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            int pre = tmp;
            tmp = (a[i] * 2) / 10;
            a[i] = (a[i] * 2) % 10 + pre;
        }
        return tmp;
    };
    auto nom_mul = [](std::vector<int> &a) {
        int n = a.size();
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            int pre = tmp;
            tmp = (a[i] * 2) / 10;
            a[i] = (a[i] * 2) % 10 + pre;
        }
        if (tmp) a.emplace_back(tmp);
    };
    auto nom_add = [](std::vector<int> &a, std::vector<int> b) {
        int m = b.size();
        while (a.size() < m) a.emplace_back(0);
        int n = a.size();
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            int pre = tmp;
            tmp = (a[i] + b[i] + tmp) / 10;
            a[i] = (a[i] + b[i] + pre) % 10;
        }
        if (tmp) a.emplace_back(tmp);
    };
    std::vector<int> hi;
    std::vector<int> lo;
    int flag = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.') {
            flag = 1;
            continue;
        }
        if (!flag)
            hi.emplace_back(s[i] - '0');
        else
            lo.emplace_back(s[i] - '0');
    }
    std::reverse(hi.begin(), hi.end());
    std::reverse(lo.begin(), lo.end());

    std::vector<int> bin;

    while (hi.size() > 0) bin.emplace_back(bin_div(hi));
    std::reverse(bin.begin(), bin.end());
    int point = bin.size();
    int time = 0, limit = 1024;
    while (lo.back() > 0 && ++time < limit) bin.emplace_back(bin_mul(lo));
    int end = point + n - 1, tmp = 0;
    std::vector<int> ans;
    if (end < bin.size()) {
        if (bin[end + 1] == 1) tmp = 1;
        std::vector<int> p;
        p.emplace_back(1);
        for (int i = end; i >= 0; --i) {
            if (bin[i] == 1) nom_add(ans, p);
            nom_mul(p);
        }
        ans[0] += tmp;
    } else {
        while (bin.size() < end) bin.emplace_back(0);
        std::vector<int> p;
        p.emplace_back(1);
        for (int i = end; i >= 0; --i) {
            if (bin[i] == 1) nom_add(ans, p);
            nom_mul(p);
        }
    }
    std::reverse(ans.begin(), ans.end());
    for (auto &x : ans) std::cout << x;
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
