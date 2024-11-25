#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Line {
    ll m, c;  // y = m * x + c
    mutable function<const Line *()> succ;
    bool operator<(const Line &rhs) const {
        if (rhs.c != numeric_limits<ll>::lowest())
            return m < rhs.m;
        const Line *s = succ();
        if (!s) return false;
        ll x = rhs.m;
        return c - s->c < (s->m - m) * x;
    }
};

struct LineContainer : multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return false;
            return y->m == z->m && y->c <= z->c;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->c <= x->c;
        return (x->c - y->c) * (z->m - y->m) >= (y->c - z->c) * (y->m - x->m);
    }
    void add(ll m, ll c) {
        auto y = insert({m, c});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll query(ll x) {
        auto l = *lower_bound((Line){x, numeric_limits<ll>::lowest()});
        return l.m * x + l.c;
    }
};

struct Rectangle {
    ll x, y, a;
};

int main() {
    int n;
    cin >> n;
    vector<Rectangle> rects(n);
    for (int i = 0; i < n; ++i) {
        cin >> rects[i].x >> rects[i].y >> rects[i].a;
    }
    sort(rects.begin(), rects.end(), [](const Rectangle &a, const Rectangle &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    });
    LineContainer cht;
    ll res = 0;
    cht.add(0, 0);
    for (auto &rect : rects) {
        ll val = cht.query(rect.y) + rect.x * rect.y - rect.a;
        res = max(res, val);
        cht.add(-rect.x, val);
    }
    cout << res << endl;
    return 0;
}
