#include<bits/stdc++.h>

#define ln '\n'

using PII = std::pair<int ,int >;
using ll = int64_t;

const int MOD = 1e9 + 7;
const int BASE = 998'244'353;

int qpow(int  x){
    int a = BASE;
    int ans =1;
    for(;x;x>>=1, a = 1LL * a * a %MOD){
        if(x& 1)ans = 1LL * ans * a % MOD;
    }
    return ans;
}


int hash(int x){
    return qpow(x);
}

struct SegmentTree{
    int n;
    std::vector<int> tag,info;
    explicit SegmentTree(int n_) : n(n_), tag(4 * n_ , 1), info(4 * n_) {}

    void pull(int p){
        info[p] = (1LL *info[2 * p ] + info[2 * p + 1])% MOD ;
    }

    void mul(int p , int v){
        tag[p] = 1LL * tag[p] * v % MOD;
        info[p] = 1LL * info[p] * v % MOD;
    }
    void push(int p){
        mul(2 * p , tag[p]);
        mul(2 * p + 1 , tag[p]);
        tag[p] = 1;
    }

    void range_mul(int p , int l , int r , int tl , int tr , int v){
        if(l >= tr || r <= tl)return;
        if(l >= tl && r <= tr)return mul(p,v);
        int m = l + r >> 1;
        push(p);
        range_mul(2*p, l , m , tl , tr , v);
        range_mul(2*p+1, m , r , tl , tr , v);
        pull(p);
    }

    int query(int p , int l , int r , int tl , int tr){
        if(l >= tr || r <= tl)return 0;
        if(l >= tl && r <= tr)return info[p];
        push(p);
        int m = l + r >> 1;
        return (query(2*p, l, m , tl , tr) + query(2*p + 1 , m , r, tl , tr)) % MOD;
    }

    void add(int p , int l , int r  , int x , int v){
        if(r - l == 1){
            info[p] = v;
            return;
        }
        int m = l + r >> 1;
        push(p);
        if(x < m)
            add(2*p , l, m , x , v);
        else 
            add(2*p + 1 , m, r , x , v);
        pull(p);
    }

    void range_mul(int tl,int tr, int v){
        range_mul(1,0,n,tl,tr,v);
    }

    int query(int tl , int tr ){
        return query(1,0,n,tl,tr);
    }

    void add( int x , int v){
        add(1,0,n,x,v);
    }

};


int main(){
    std::ios::sync_with_stdio(false), std::cin.tie(0);
    int _ = 1;
//    std::cin >> _;
    auto solve = [&]() -> void {
        int n,m;
        std::cin >> n >> m;
        SegmentTree odd(n + 1);
        SegmentTree eve(n + 1);
        for(int i =1 , x ;i<=n;++i){
            std::cin >> x;
            x = hash(x);
            if(i & 1)odd.add((i + 1) >> 1,x);
            else eve.add(i >> 1,x);
        }
        for(int i =0;i<m;++i){
            int op, l , r ;
            std::cin >> op >> l >> r;
            int oddl = (l & 1) ? (l + 1) >> 1 : (l >> 1) + 1;
            int oddr = (r & 1) ? (r + 1) >> 1 : r >> 1;

            int evel = (l & 1) ? (l + 1) >> 1 : l >> 1;
            int ever = (r & 1) ? (r - 1) >> 1 : r >> 1;

            if(op == 0){
                int x;
                std::cin >> x;
                x = hash(x);
                odd.range_mul(oddl,oddr + 1, x);
                eve.range_mul(evel,ever + 1, x);
            }else{
                std::cout << ((odd.query(oddl,oddr + 1) == eve.query(evel,ever + 1)) ? "Yes\n": "No\n");
            }

        }

    };
    while(_--)solve();
    return 0;
}
