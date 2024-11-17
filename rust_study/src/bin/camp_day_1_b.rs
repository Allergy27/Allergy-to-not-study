//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_1_b.rs
//@data      2024/11/16 11:08:09
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

const MOD: i64 = 1_000_000_007;

// 快速幂计算 (base^exp) % MOD
fn _qpow(base: i64, exp: i64) -> i64 {
    let mut result = 1;
    let mut b = base % MOD;
    let mut e = exp;
    while e > 0 {
        if e % 2 == 1 {
            result = result * b % MOD;
        }
        b = b * b % MOD;
        e /= 2;
    }
    result
}

fn solve() {
    let n = cin!(usize);
    let qwq = cin!([usize; n]);
    let max_a = 1_000_000;
    let mut cnt = vec![0; max_a + 1];

    for &num in &qwq {
        cnt[num] += 1;
    }

    // c[g]：数组中是 g 倍数的数字个数
    let mut c = vec![0usize; max_a + 1];
    for g in 1..=max_a {
        let mut tmp = g;
        while tmp <= max_a {
            c[g] += cnt[tmp];
            tmp += g;
        }
    }
    // S[g]：所有元素是 g 倍数的子序列数量
    let mut s = vec![0i64; max_a + 1];
    // E[g]：所有元素是 g 倍数的子序列的元素总长度
    let mut e = vec![0i64; max_a + 1];

    // 预先计算 2 的幂次以避免重复计算
    let mut pow2 = vec![0i64; c.iter().max().unwrap() + 1];
    pow2[0] = 1;
    for i in 1..pow2.len() {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    // 计算 S[g] 和 E[g]
    for g in 1..=max_a {
        if c[g] > 0 {
            s[g] = (pow2[c[g]] + MOD - 1) % MOD; // S[g] = 2^{c[g]} - 1
            e[g] = c[g] as i64 * pow2[c[g] - 1] % MOD; // E[g] = c[g] * 2^{c[g]-1}
        }
    }

    // 应用包含-排除原则
    for g in (1..=max_a).rev() {
        let mut tmp = 2 * g;
        while tmp <= max_a {
            s[g] = (s[g] + MOD - s[tmp]) % MOD;
            e[g] = (e[g] + MOD - e[tmp]) % MOD;
            tmp += g;
        }
    }

    // 计算总强度
    let mut ans = 0i64;
    for g in 2..=max_a {
        ans = (ans + e[g] * g as i64 % MOD) % MOD;
    }

    println!("{}", ans);
}
