// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Leetcode\2901.cpp
 * @date      2025/05/16 13:07:42
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        using std::vector;
        using std::string;
        using std::unordered_map;
        using std::array;
        using std::tuple;
        auto leetcode = [](vector<string>& words, vector<int> groups) -> vector<string> {
            int n = words.size();
            unordered_map<int64_t, tuple<int, int, int, int>> f_map;
            vector<int> from(n);
            int global_max_f = 0, max_i = 0;
            for (int i = n - 1; i >= 0; i--) {
                string& w = words[i];
                int g = groups[i];
                int64_t hash = 0;
                for (char ch : w) hash = (hash << 5) | (ch & 31);
                int f = 0;
                for (int k = 0; k < w.size(); k++) {
                    int64_t h = hash | (31LL << (k * 5));
                    auto& [max_f, j, max_f2, j2] = f_map[h];
                    if (g != groups[j]) {
                        if (max_f > f) {
                            f = max_f;
                            from[i] = j;
                        }
                    } else {
                        if (max_f2 > f) {
                            f = max_f2;
                            from[i] = j2;
                        }
                    }
                }
                if (f++ > global_max_f) {
                    global_max_f = f;
                    max_i = i;
                }
                for (int k = 0; k < w.size(); k++) {
                    int64_t h = hash | (31LL << (k * 5));
                    auto& [max_f, j, max_f2, j2] = f_map[h];
                    if (f > max_f) {
                        if (g != groups[j]) {
                            max_f2 = max_f;
                            j2 = j;
                        }
                        max_f = f;
                        j = i;
                    } else if (f > max_f2 && g != groups[j]) {
                        max_f2 = f;
                        j2 = i;
                    }
                }
            }
            vector<string> ans(global_max_f);
            int i = max_i;
            for (int k = 0; k < global_max_f; k++) {
                ans[k] = words[i];
                i = from[i];
            }
            return ans;
        };
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
