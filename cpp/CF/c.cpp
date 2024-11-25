void solve(int CaseNum) {
    int x = read(), m = read();
    for (int y = 1; y <= min(x, m); ++y) { // 替换 rep(y, 1, min(x, m))
        int o = x ^ y;
        if (o % x == 0 && o % y == 0) {
            ans++;
            // debug("1", x, y, o, m);
        }
    }
    {
        int cnt = m / x;
        ans += cnt;
        int ret = 0;
        for (int mul = max(2LL, cnt - 2); mul <= cnt; ++mul) { // 替换 rep(mul, max(2LL, cnt - 2), cnt + 1)
            int o = x * mul;
            int y = o ^ x;
            if (o % x == 0 && o % y && y > m) {
                ans--;
            }
        }
        debug(ret);
    }
    {
        if (x <= m) {
            int y = x;
            int o = x ^ y;
            if (o % x == 0 && o % y == 0) {
                ans++;
                // debug("3", x, y, o, m);
            }
        }
    }
    w(ans);
}
