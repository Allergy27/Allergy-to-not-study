#include "bits/stdc++.h"

using namespace std;
#define ll long long
#define int long long
#define ULL unsigned long long
#define mem(f, x) memset(f, x, sizeof(f))
#define rep(i, a, b) for (int i = a; i <= (int)b; ++i)
#define per(i, a, b) for (int i = a; i >= (int)b; --i)
#define all(x) (x).begin(), (x).end()
#define warr(arr, n) rep(i, 1, n) printf("%lld%c", arr[i], " \n"[i == n])
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define nline '\n'
#define pii pair<int, int>
#define yes printf("Yes\n")
#define no printf("No\n")
#define lowbit(x) ((-(x)) & (x))
#define uniquev(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define w(x) cout << x << '\n'
#ifdef qhyer
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
clock_t startTime;

template <typename A, typename B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
    out << "(" << a.first << "," << a.second << ")";
    return out;
}

template <typename T, size_t N>
ostream &operator<<(ostream &out, const array<T, N> &a) {
    out << "[";
    bool first = true;
    for (auto &v : a) {
        out << (first ? "" : ", ");
        out << v;
        first = false;
    }
    out << "]";
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &a) {
    out << "[";
    bool first = true;
    for (auto v : a) {
        out << (first ? "" : ", ");
        out << v;
        first = false;
    }
    out << "]";
    return out;
}

template <typename T, class Cmp>
ostream &operator<<(ostream &out, const set<T, Cmp> &a) {
    out << "{";
    bool first = true;
    for (auto &v : a) {
        out << (first ? "" : ", ");
        out << v;
        first = false;
    }
    out << "}";
    return out;
}

template <typename T, class Cmp>
ostream &operator<<(ostream &out, const multiset<T, Cmp> &a) {
    out << "{";
    bool first = true;
    for (auto &v : a) {
        out << (first ? "" : ", ");
        out << v;
        first = false;
    }
    out << "}";
    return out;
}

template <typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const map<U, T, Cmp> &a) {
    out << "{";
    bool first = true;
    for (auto &p : a) {
        out << (first ? "" : ", ");
        out << p.first << ":" << p.second;
        first = false;
    }
    out << "}";
    return out;
}

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

template <class T>
auto vect(const T &v, int n) { return vector<T>(n, v); }

template <class T, class... D>
auto vect(const T &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}

double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const double eps = 1e-7;
const int mod = 998244353;
const int N = 1e6 + 10, M = 510;

inline ll gcd(ll a, ll b) {
    if (!a)
        return b;
    if (!b)
        return a;
    ll x = __builtin_ctzll(a | b);
    a >>= __builtin_ctzll(a);
    do {
        b >>= __builtin_ctzll(b);
        if (a > b) {
            ll t = b;
            b = a, a = t;
        }
        b -= a;
    } while (b);
    return a << x;
}

inline int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

inline int qpow(int x, ll y, int m = mod) {
    int r = 1;
    for (; y; y >>= 1, x = (ll)x * x % m) {
        if (y & 1) {
            r = (ll)r * x % m;
        }
    }
    return r;
}

mt19937_64 mrand(random_device{}());

int64_t rnd(int64_t x) { return mrand() % x; }

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

template <const int T>
struct ModInt {
    const static int mod = T;
    int x;

    ModInt(int x = 0) : x(x % mod) {
    }

    int val() { return x; }

    ModInt operator+(const ModInt &a) const {
        int x0 = x + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }

    ModInt operator-(const ModInt &a) const {
        int x0 = x - a.x;
        return ModInt(x0 < mod ? x0 + mod : x0);
    }

    ModInt operator*(const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }

    ModInt operator/(const ModInt &a) const { return *this * a.inv(); }

    void operator+=(const ModInt &a) {
        x += a.x;
        if (x >= mod) x -= mod;
    }

    void operator-=(const ModInt &a) {
        x -= a.x;
        if (x < 0) x += mod;
    }

    void operator*=(const ModInt &a) { x = 1LL * x * a.x % mod; }

    void operator/=(const ModInt &a) { *this = *this / a; }

    friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x; }

    ModInt pow(int64_t n) const {
        ModInt res(1), mul(x);
        while (n) {
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
};

typedef ModInt<mod> mint;

ll _tc = 1;
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dir[] = {1, 0, -1, 0, 1};
ll n, m, k, q;
ll ans;
bool flag;
ll a[N];

int ask_cnt = 0;
bool ask(int x, int y) {
    ask_cnt++;
    cout << "? " << x << " " << y << endl;
    int ret = read();
    if (ret == -1)
        while (true);
    return ret == 0;
    // return true;
}

int rel;

vector<int> v, na, nb;

void work(int l, int r) {
    if (!na.empty()) {
        if (ask(na.back(), l)) {
            for (auto x : nb) v.push_back(x);
        } else {
            for (auto x : na) v.push_back(x);
        }
        return;
    }
    if (rel && l == 981) {
        int rel_cnt = 0;
        rep(i, l, r - 1) {
            if (ask(rel, i)) {
                rel_cnt++;
            } else {
                v.push_back(i);
            }
        }
        if (rel_cnt == 10) v.push_back(1000);
        return;
    }
    rep(i, l, r - 1) {
        if (ask(i, i + 1)) {
            a[i + 1] = a[i];
        } else {
            a[i + 1] = a[i] ^ 1;
        }
    }
    map<int, vector<int>> cnts;
    rep(i, l, r) {
        cnts[a[i]].push_back(i);
    }
    if (cnts[1].size() < cnts[0].size()) {
        for (auto c : cnts[1]) {
            v.push_back(c);
        }
        rel = cnts[0].back();
    } else if (cnts[1].size() > cnts[0].size()) {
        for (auto c : cnts[0]) {
            v.push_back(c);
        }
        rel = cnts[1].back();
    } else {
        for (auto c : cnts[0]) {
            na.push_back(c);
        }
        for (auto c : cnts[1]) {
            nb.push_back(c);
        }
    }
    debug(cnts, v, na, nb, rel);
}

void solve(int CaseNum) {
    n = read(), m = read(), k = read();
    rep(i, 1, 1000) {
        work(i, i + 19);
        i += 19;
    }
    cout << "! ";
    for (int i = 0; i < 10; i++) cout << v[i] << ' ';
    cout << endl;
    debug(ask_cnt);
}

void init() {
#ifdef qhyer

#endif
}

signed main() {
#ifdef qhyer
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    startTime = clock();
#endif
    // scanf("%lld", &_tc);
    init();
    rep(_i, 1, _tc) {
        debug(_i, "=====================");
        ans = 0;
        flag = false;
        solve(_i);
#ifdef qhyer
        puts("\n=====================\n");
#endif
    }
#ifdef qhyer
    cout << endl
         << "totalTs: " << getCurrentTime() << endl;
#endif
    return 0;
}
