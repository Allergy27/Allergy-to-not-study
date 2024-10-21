#include <bits/stdc++.h>  // NOLINT
#define int long long  // NOLINT
#define inf 0x3f3f3f3f
using namespace std;  // NOLINT
using pii = pair<int, int>;
const int N = 1e6 + 5;
struct pos {
    int a, b;
} w[N];
bool cmp(pos &x1, pos &x2) {  // NOLINT
    int aa[5];
    aa[1] = x1.a, aa[2] = x1.b, aa[3] = x2.a, aa[4] = x2.b;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = i + 1; j <= 4; j++) {
            if (aa[i] > aa[j])
                ans1++;
        }
    }

    swap(aa[1], aa[3]);
    swap(aa[2], aa[4]);
    for (int i = 1; i <= 3; i++) {
        for (int j = i + 1; j <= 4; j++) {
            if (aa[i] > aa[j])
                ans2++;
        }
    }
    if (ans1 == ans2) {
        int y1 = abs(x1.a - x1.b);
        int y2 = abs(x2.a - x2.b);
        if (y1 == y2) {
            return x1.a < x2.a;
        }
        return y1 < y2;
    }
    return ans1 < ans2;
}
void work() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i].a >> w[i].b;
    }
    sort(w + 1, w + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        cout << w[i].a << ' ' << w[i].b << ' ';
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        work();
    }
    return 0;
}