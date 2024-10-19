/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace IntroductionToAlgorithm\ChapterNULL\xm_xk_ji.cpp
 *@date      2024/09/14 07:56:32
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, a_sum = 0, b_sum = 0;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n);
    vector<int>p(n);

    for(int &x : a) {
        cin >> x;
        a_sum ^= x;
    }
    for(int &x : b) {
        cin >> x;
        b_sum ^= x;
    }
    for(int i = 0;i < n;++i)p[i] = a[i] ^ b[i];
    auto deg = [](int num, int deg) {
        return num & (1 << deg);
        };

    int row = 0;
    for(int col = 35; ~col && row < n; --col) {
        for(int i = row; i < n; ++i) {
            if(deg(p[i], col)) {
                std::swap(p[row], p[i]);
                break;
            }
        }
        if(!deg(p[row], col)) continue;
        for(int i = 0; i < n; ++i) {
            if(i == row) continue;
            if(deg(p[i], col)) {
                p[i] ^= p[row];
            }
        }
        ++row;
    }
    for(int i = row; i > 0;--i) {
        auto check = [&](auto const &self, int i, bool t) ->int {
            int q = p[i - 1], flag = false;
            if(q == 0) return max(a_sum, b_sum);
            int asum = t ? a_sum ^ q : a_sum, bsum = t ? b_sum ^ q : b_sum;
            bool bit_a = (asum >> i) & 1, bit_b = (bsum >> i) & 1;
            if(bit_a && bit_b) {
                flag = true;
            }
            else if(bit_a || bit_b) {
                if(max(asum ^ q, bsum ^ q) < max(asum, bsum))flag = true;
            }
            return max(asum ^ q, bsum ^ q);
            };
        int q = p[i - 1];
        if(q == 0) continue;
        bool bit_a = (a_sum >> i) & 1, bit_b = (b_sum >> i) & 1;
        if(bit_a && bit_b) {
            a_sum ^= q;
            b_sum ^= q;
        }
        else if(bit_a || bit_b) {
            if(check(check, i - 1, true) < check(check, i - 1, false)) {
                a_sum ^= q;
                b_sum ^= q;
            }
        }
    }
    cout << max(a_sum, b_sum) << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}