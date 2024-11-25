// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\ACM\11.16\c.cpp
 * @date      2024/11/16 11:40:26
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
int inf = 0x3f3f3f3f;
int ll_inf = 0x3f3f3f3f3f3f3f3f;

// 快速幂计算 (base^exp) % mod
int qmul(int a, int b, int mod) {
    int result = 0;
    a %= mod;
    while (b) {
        if (b & 1) result = (result + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}

int qpow(int a, int b, int mod) {
    int result = 1;
    a %= mod;
    while (b) {
        if (b & 1) result = qmul(result, a, mod);
        a = qmul(a, a, mod);
        b >>= 1;
    }
    return result;
}

// Miller-Rabin 素性测试
bool miller_rabin(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    int test_times = 10;
    for (int i = 0; i < test_times; i++) {
        int a = rand() % (n - 2) + 2;  // NOLINT
        int x = qpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool flag = false;
        for (int r = 1; r < s; r++) {
            x = qmul(x, x, n);
            if (x == n - 1) {
                flag = true;
                break;
            }
        }
        if (!flag) return false;
    }
    return true;
}

signed main() {
    srand(time(0));
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << (miller_rabin(x) ? "YES" : "NO") << '\n';
    }
    return 0;
}
