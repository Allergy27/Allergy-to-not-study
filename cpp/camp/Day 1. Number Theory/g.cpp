// COPYRIGHT
#include <bits/stdc++.h>
#define int int64_t
using namespace std;  // NOLINT

vector<int> computeEulerPhi(int n) {
    vector<int> phi(n + 1);
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);

    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= n; ++j) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            } else {
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            }
        }
    }

    return phi;
}

void solve() {
    int n;
    cin >> n;
    vector<int> phi = computeEulerPhi(n);
    int result = 0;

    // 遍历 d，从 1 到 n
    for (int d = 1; d <= n; ++d) {
        int k = n / d;
        result += phi[d] * k * k;  // 累加结果
    }
    cout << result << endl;
}

// 测试主函数
signed main() {
    solve();
    return 0;
}
