#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> S(m);
        for (auto &x : S)
            cin >> x;
        // 按降序排序S以获得字典序最大的数组
        sort(S.begin(), S.end(), greater<int>());
        // 初始化结果数组
        vector<int> a(n, -1);
        bool possible = true;
        // 预处理每个位置i的所有约数d
        vector<vector<int>> divisors(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                divisors[j].push_back(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (auto x : S) {
                bool valid = true;
                // 检查所有d = gcd(i,j)的情况
                for (auto d : divisors[i]) {
                    if (d < i) {
                        if (a[d - 1] != -1 && __gcd(x, a[d - 1]) == a[d - 1]) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (valid) {
                    a[i - 1] = x;
                    break;
                }
            }
            if (a[i - 1] == -1) {
                possible = false;
                break;
            }
        }
        if (possible) {
            for (auto num : a)
                cout << num << " ";
            cout << "\n";
        } else
            cout << "-1\n";
    }
}