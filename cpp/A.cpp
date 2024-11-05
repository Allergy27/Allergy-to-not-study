// COPYRIGHT: 2021-2022 All Rights Reserved
#include <bits/stdc++.h>  // NOLINT
using namespace std;      // NOLINT
typedef int64_t ll;
int n, m, a[200100], l[200100], r[200100], stk[200100], tp, lim, mil;
ll res[200100];
namespace BIT1 {            // a BIT for triangular summary.
ll t1[600100], t2[600100];  // t1 for weighted sum, t2 for common sum.
void ADD(int x, int y) {
    x--;
    ll tmp = 1ll * y * x;
    for (int i = x + n + 1; i <= 3 * n; i += i & -i) t1[i] += tmp, t2[i] += y;
}
ll SUM(int x) {
    ll ret = 0;
    for (int i = x + n + 1; i; i -= i & -i) ret -= t1[i], ret += t2[i] * x;
    return ret;
}
}  // namespace BIT1
namespace BIT2 {
ll t1[600100], t2[600100];
void ADD(int x, int y) {
    x++;
    ll tmp = 1ll * y * x;
    for (int i = x + n + 1; i; i -= i & -i) t1[i] += tmp, t2[i] += y;
}
ll SUM(int x) {
    ll ret = 0;
    for (int i = x + n + 1; i <= 3 * n; i += i & -i) ret += t1[i], ret -= t2[i] * x;
    return ret;
}
}  // namespace BIT2
void ADD1(int x, int y, int z) { BIT1::ADD(x - y, z); }
void ADD2(int x, int y, int z) { BIT2::ADD(y, z); }
struct Query {
    int x, y, id;
    Query(int u = 0, int v = 0, int w = 0) { x = u, y = v, id = w; }  // NOLINT
    friend bool operator<(const Query &x, const Query &y) { return x.x < y.x; }
} q[400100];
struct Tri {
    int x, y, a;
    Tri(int u = 0, int v = 0, int w = 0) { x = u, y = v, a = w; }  // NOLINT
    friend bool operator<(const Tri &x, const Tri &y) { return x.x < y.x; }
} p[800100];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    // 单调栈找左端点
    for (int i = n; i >= 1; i--) {
        while (tp && a[i] > a[stk[tp]]) l[stk[tp--]] = i;
        stk[++tp] = i;
    }
    while (tp) l[stk[tp]] = stk[tp] - n - 1, tp--;

    // 单调栈找右端点
    for (int i = 1; i <= n; i++) {
        while (tp && a[stk[tp]] <= a[i]) r[stk[tp--]] = i;
        stk[++tp] = i;
    }
    while (tp) r[stk[tp--]] = n + 1;

    // 初始化树状数组1，扫描线事件树
    for (int i = 1; i <= n; i++) {
        p[++lim] = Tri(i - 1, i - l[i] - 2, -a[i]);
        p[++lim] = Tri(r[i] - 1, r[i] - l[i] - 2, a[i]);
        p[++lim] = Tri(r[i] - 1, r[i] - i - 2, -a[i]);
    }
    for (int i = 1; i <= lim; i++) ADD1(p[i].x, p[i].y, p[i].a);
    sort(p + 1, p + lim + 1);

    // 初始化树状数组2，扫描线查询
    for (int i = 1, t, l, r; i <= m; i++) {
        scanf("%d%d%d", &t, &l, &r);
        q[++mil] = Query(l - 1, t, -i);
        q[++mil] = Query(r, t, i);
    }
    sort(q + 1, q + mil + 1);

    // 处理查询
    for (int i = 1, j = 1; i <= mil; i++) {
        while (j <= lim && p[j].x < q[i].x) ADD1(p[j].x, p[j].y, -p[j].a), ADD2(p[j].x, p[j].y, p[j].a), j++;
        int lambda = (q[i].id > 0 ? 1 : -1);
        q[i].id = abs(q[i].id);
        res[q[i].id] += (BIT1::SUM(q[i].x - q[i].y) + BIT2::SUM(q[i].y)) * lambda;
    }
    for (int i = 1; i <= m; i++) printf("%lld\n", res[i]);
    //  for(int i=1;i<=n;i++)printf("%d %d\n",l[i],r[i]);
    return 0;
}
