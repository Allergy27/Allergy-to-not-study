    // Copyright 2024 Allergy
    /* @author    Allergy
    * @email     Allergy527@gmail.com
    * @workspace cpp\NowCode\round69\f.cpp
    * @date      2024/11/24 20:31:06
    */
    #include <bits/stdc++.h>
    #define lowbit(x) ((x) & (-(x)))
    #define ln '\n'
    #define int int64_t

    using namespace std;  // NOLINT
    using ll = int64_t;
    int inf = 0x3f3f3f3f;
    ll ll_inf = 0x3f3f3f3f3f3f3f3f;

    struct Node {
        int cnt_r, cnt_e, cnt_d;
        int cnt_re, cnt_red;
        Node() : cnt_r(0), cnt_e(0), cnt_d(0), cnt_re(0), cnt_red(0) {}
    };

    vector<Node> tree_s, tree_t;
    int n, q;
    string s, t;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.cnt_r = left.cnt_r + right.cnt_r;
        res.cnt_e = left.cnt_e + right.cnt_e;
        res.cnt_d = left.cnt_d + right.cnt_d;
        res.cnt_re = left.cnt_re + left.cnt_r * right.cnt_e + right.cnt_re;
        res.cnt_red = left.cnt_red + left.cnt_re * right.cnt_d + right.cnt_red;
        return res;
    }

    void build(vector<Node>& tree, const string& str, int idx, int l, int r) {
        if (l == r) {
            if (str[l - 1] == 'r')
                tree[idx].cnt_r = 1;
            else if (str[l - 1] == 'e')
                tree[idx].cnt_e = 1;
            else if (str[l - 1] == 'd')
                tree[idx].cnt_d = 1;
        } else {
            int mid = (l + r) / 2;
            build(tree, str, idx * 2, l, mid);
            build(tree, str, idx * 2 + 1, mid + 1, r);
            tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
        }
    }

    void update(vector<Node>& tree, int idx, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[idx] = Node();
            if (ch == 'r')
                tree[idx].cnt_r = 1;
            else if (ch == 'e')
                tree[idx].cnt_e = 1;
            else if (ch == 'd')
                tree[idx].cnt_d = 1;
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid)
                update(tree, idx * 2, l, mid, pos, ch);
            else
                update(tree, idx * 2 + 1, mid + 1, r, pos, ch);
            tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
        }
    }

    Node query(const vector<Node>& tree) {
        return tree[1];
    }

    void solve() {
        cin >> n >> q;
        cin >> s >> t;
        tree_s.resize(n * 4);
        tree_t.resize(n * 4);
        build(tree_s, s, 1, 1, n);
        build(tree_t, t, 1, 1, n);
        for (int i = 0; i < q; ++i) {
            int x;
            cin >> x;
            char ch_s = s[x - 1], ch_t = t[x - 1];
            swap(s[x - 1], t[x - 1]);
            update(tree_s, 1, 1, n, x, s[x - 1]);
            update(tree_t, 1, 1, n, x, t[x - 1]);
            int res = query(tree_s).cnt_red - query(tree_t).cnt_red;
            cout << res << '\n';
        }
    }

    signed main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int t = 1;
        // cin >> t;
        while (t--) solve();
        return 0;
    }
