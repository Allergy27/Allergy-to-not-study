// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round69\d.cpp
 * @date      2024/11/24 19:33:49
 */
#include <bits/stdc++.h>
using namespace std;  // NOLINT
const long long ll_inf = 0x3f3f3f3f3f3f3f3f;  // NOLINT

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> grass(n, vector<int>(m, 0));
    vector<int> ans;
    for (auto &x : grass) {
        string s;
        cin >> s;
        for (int i = 0; i < m; ++i) x[i] = s[i] - '0';
    }
    vector<vector<vector<int>>> plans(q, vector<vector<int>>(n, vector<int>(m, 0)));
    for (int i = 0; i < q; ++i) {
        for (auto &x : plans[i]) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) x[j] = s[j] - '0';
        }
    }

    vector<int> best_ans;
    int best_size = q + 1;

    auto dfs = [&](auto self, int idx, vector<vector<int>> res, vector<int> selected) -> void {
        if (idx == q) {
            bool valid = true;
            for (int i = 0; i < n && valid; ++i) {
                for (int j = 0; j < m && valid; ++j) {
                    if (grass[i][j] == 1 && res[i][j] == 1) valid = false;
                    if (grass[i][j] == 0 && res[i][j] == 0) valid = false;
                }
            }
            if (valid && selected.size() < best_size) {
                best_size = selected.size();
                best_ans = selected;
            }
            return;
        }

        self(self, idx + 1, res, selected);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] |= plans[idx][i][j];
            }
        }
        selected.push_back(idx + 1);
        self(self, idx + 1, res, selected);
    };

    vector<vector<int>> initial_res(n, vector<int>(m, 0));
    dfs(dfs, 0, initial_res, {});

    if (best_size == q + 1) {
        cout << -1 << endl;
    } else {
        cout << best_size << endl;
        for (int i = 0; i < best_size; ++i) {
            cout << best_ans[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
