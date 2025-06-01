/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_17\8_9_1_Maxflow_2065.cpp
 * @date      2025/05/17 19:43:38
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

class Dinic {
 public:
    struct Node {
        int to, cep;
        Node *re;
        explicit Node(int t, int c) : to(t), cep(c), re(nullptr) {}
    };

 private:
    std::vector<std::vector<Node *>> qwq;
    std::vector<int> level, ptr;
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> m >> n;
        std::vector<int> blue(m), red(n);
        for (auto &x : blue) std::cin >> x;
        for (auto &x : red) std::cin >> x;
        std::vector qwq(n + m + 2, std::vector<int>(n + m + 2));
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
