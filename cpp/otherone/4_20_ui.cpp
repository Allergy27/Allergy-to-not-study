#include <bits/stdc++.h>
using namespace std;
//#define int int64_t
#define pb push_back
#define ln '\n'
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define ull unsigned long long
const int MAXN = 1e5+5;
const int mod = 1e6+7;
const int MOD = 1e9+7;

int n;
int a[105][105], ac[105][105];
int mox[] = {0, 0, 1, -1, 0, 0, 2, -2, 1, 1, -1, -1},
    mov[] = {1, -1, 0, 0, 2, -2, 0, 0, 1, -1, 1, -1},
    mow[] = {0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2};
struct node{
    int x, y, w;
    bool operator<(const node &rhs)const{
        return w > rhs.w;
    }
};

void bfs(){
    priority_queue<node> q;
    q.push(node{1, 1, a[1][1]});
    ac[1][1] = 0;
    while (!q.empty()){
        node p = q.top();
        q.pop();
        for (int i = 0; i < 12;i++){
            int mx = p.x + mov[i],
                my = p.y + mov[i],
                mw = p.w + mov[i];
            if(mx<1||mx>n||my<1||my>n)continue;
            if(a[p.x][p.y]!=a[mx][my])mw++;
            if(ac[mx][my]<ac[p.x][p.y]+mw){
                ac[mx][my] = ac[p.x][p.y] + mw;
                q.push(node{mx, my, ac[mx][my]});
            }
        }
    }
}

void solve(){
    memset(ac, MOD, sizeof(ac));
    int m, x, y, f;
    cin >> n >> m;
    cout << ac[3][3] << ln;
    for (int i = 1; i < m;i++){
        cin >> x >> y >> f;
        a[x][y] = 2 - f;
    }
    bfs();
    if(ac[n][n]==MOD)ac[n][n] = -1;
    cout << ac[n][n] << ln;
    return;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)solve();
    return 0;
}