//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_988_div3_g.rs
//@data      2024/11/17 23:41:14
#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    }};
    ([$type:ty;$n:expr]) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        let mut arr = Vec::with_capacity($n as usize);
        for _ in 0..$n {
            arr.push((s.next().unwrap()).parse::<$type>().unwrap());
        }
        arr
    }};
    ($type:ty) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        (s.next().unwrap()).parse::<$type>().unwrap()
    }};

    ($($type:ty),*) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        ($(s.next().unwrap().parse::<$type>().unwrap()),*)
    }}
}
fn main() {
    let t = 1;
    //let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
use std::collections::{HashMap, HashSet};

fn solve() {
    let n = cin!(usize);
    let a = cin!([usize; n]);
    const MOD: usize = 998244353;
    let mut dp = vec![0usize; n];
    dp[0] = 1;

    let mut sieve = vec![0usize; 1_000_001];
    for i in 2..sieve.len() {
        if sieve[i] == 0 {
            for j in (i..sieve.len()).step_by(i) {
                sieve[j] = i;
            }
        }
    }

    let mut positions: HashMap<usize, usize> = HashMap::new();

    for i in 0..n {
        let mut x = a[i];
        let mut primes = HashSet::new();
        while x > 1 {
            primes.insert(sieve[x]);
            x /= sieve[x];
        }
        let mut min_pos = n;
        for &p in &primes {
            if let Some(&pos) = positions.get(&p) {
                min_pos = min_pos.min(pos);
            }
            positions.insert(p, i);
        }
        if min_pos < n {
            dp[i] = (dp[i] + dp[min_pos]) % MOD;
        }
        if i > 0 {
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        }
    }

    let result = dp[n - 1] % MOD;
    println!("{}", result);
}
