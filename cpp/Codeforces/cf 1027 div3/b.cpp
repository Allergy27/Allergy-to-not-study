#include<bits/stdc++.h>

#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n");
#define ln '\n'

using ll = int64_t;
using PII = std::pair<int,int>;

int main(){
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    auto solve = [&](){
        int n, m;
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        std::array<int , 2> qwq{};
        for(int i =0;i<n;++i)++qwq[s[i] - '0'];
        int mx = qwq[0] / 2 + qwq[1] / 2;
        int mi = std::max(qwq[0], qwq[1]) - n / 2;
        judge(m >= mi && (m - mi) % 2 == 0 && m <= mx);

    };
    while(_--)solve();
    return 0;
}
