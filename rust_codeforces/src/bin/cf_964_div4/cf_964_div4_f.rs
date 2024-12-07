//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_964_div4_f.rs
//@data      2024/12/03 07:42:34
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
    // let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let t = cin!(i64);
    const MOD: i64 = 1_000_000_007;
    let qpow = |base: i64, exp: i64, modulus: i64| -> i64 {
        let mut result = 1;
        let mut base = base % modulus;
        let mut exp = exp;
        while exp > 0 {
            if exp % 2 == 1 {
                result = result * base % modulus;
            }
            base = base * base % modulus;
            exp /= 2;
        }
        result
    };

    let max_n = 200_007;
    // 阶乘数组 fact[i] 存储 i! % MOD
    let mut fact = vec![1; max_n + 1];
    // 逆阶乘数组 inv_fact[i] 存储 (i!)^-1 % MOD
    let mut inv_fact = vec![1; max_n + 1];

    // 计算阶乘
    for i in 1..=max_n {
        fact[i] = fact[i - 1] * i as i64 % MOD;
    }

    // 计算逆阶乘, 使用快速幂求逆元
    inv_fact[max_n] = qpow(fact[max_n], MOD - 2, MOD); // 根据费马小定理计算 (fact[max_n])^(MOD-2) % MOD
    for i in (1..max_n).rev() {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) as i64 % MOD;
    }
    let comb = |n: i64, k: i64| -> i64 {
        if k > n || k < 0 {
            return 0;
        }
        // 计算组合数: C(n, k) = fact[n] * inv_fact[k] * inv_fact[n - k] % MOD
        fact[n as usize] * inv_fact[k as usize] % MOD * inv_fact[(n - k) as usize] % MOD
    };

    for _ in 0..t {
        let (n, k) = cin!(i64, i64);
        let qwq = cin!([i64; n]);
        let s = qwq.iter().filter(|x| **x == 1).count() as i64;
        let m = (k + 1) / 2;
        let mut ans = 0;
        if m <= s {
            for i in m..=(k.min(s)) {
                let c1 = comb(s, i);
                let c2 = comb(n - s, k - i);
                ans = (ans + c1 * c2) % MOD
            }
        }
        println!("{ans}")
    }
}
