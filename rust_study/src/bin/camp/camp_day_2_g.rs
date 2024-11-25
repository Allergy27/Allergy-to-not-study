//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_2_g.rs
//@data      2024/11/17 12:24:55
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
const MOD: u64 = 998_244_353;

// 计算 (a * b) % MOD
fn mul(a: Vec<u64>, b: Vec<u64>) -> Vec<u64> {
    let n = a.len();
    let mut res = vec![0; 2 * n];
    for i in 0..n {
        for j in 0..n {
            res[i + j] = (res[i + j] + a[i] * b[j]) % MOD;
        }
    }
    res
}

// 多项式取模
fn mod_poly(a: Vec<u64>, mod_poly: &Vec<u64>) -> Vec<u64> {
    let mut res = a.clone();
    let n = mod_poly.len() - 1;
    while res.len() >= mod_poly.len() {
        let coef = res.pop().unwrap();
        if coef != 0 {
            for i in 0..n {
                let idx = res.len().wrapping_sub(n).wrapping_add(i);
                if idx < res.len() {
                    res[idx] = (res[idx] + MOD - coef * mod_poly[i] % MOD) % MOD;
                }
            }
        }
    }
    res
}
// Berlekamp-Massey 算法
fn berlekamp_massey(s: &[u64]) -> Vec<u64> {
    let mut n = s.len();
    let mut c = vec![0u64; n];
    let mut b = vec![0u64; n];
    c[0] = 1;
    b[0] = 1;
    let mut l = 0;
    let mut m = 1;
    let mut bb = 1;
    for i in 0..n {
        let mut d = s[i];
        for j in 1..=l {
            d = (d + c[j] * s[i - j]) % MOD;
        }
        if d == 0 {
            m += 1;
            continue;
        }
        let coef = d * modinv(bb, MOD) % MOD;
        let mut temp = c.clone();
        for j in m..n {
            c[j] = (c[j] + MOD - coef * b[j - m] % MOD) % MOD;
        }
        if 2 * l <= i {
            l = i + 1 - l;
            b = temp;
            bb = d;
            m = 1;
        } else {
            m += 1;
        }
    }
    c.resize(l + 1, 0);
    c.reverse();
    c
}

// 求逆元
fn modinv(a: u64, m: u64) -> u64 {
    qpow(a, m - 2, m)
}

// 快速幂
fn qpow(mut base: u64, mut exp: u64, m: u64) -> u64 {
    let mut res = 1;
    base %= m;
    while exp > 0 {
        if exp % 2 == 1 {
            res = res * base % m;
        }
        base = base * base % m;
        exp /= 2;
    }
    res
}

// 线性递推计算第 k 项
fn get_kth(rec: &[u64], init: &[u64], k: usize) -> u64 {
    let n = rec.len();
    let mut s = vec![0u64; n];
    s[1] = 1;
    let mut a = vec![0u64; n];
    a[0] = 1;
    let mut k = k;
    while k > 0 {
        if k % 2 == 1 {
            a = mod_poly(mul(a, s.clone()), &rec.to_vec());
        }
        s = mod_poly(mul(s.clone(), s.clone()), &rec.to_vec());
        k /= 2;
    }
    let mut res = 0;
    for i in 0..n {
        res = (res + a[i] * init[i]) % MOD;
    }
    res
}

fn main() {
    let (n, m) = cin!(usize, usize);
    let a = cin!([u64; n]);
    let c = berlekamp_massey(&a);
    let init = a.clone();

    for i in n..n + m {
        let val = get_kth(&c, &init, i);
        print!("{}{}", val, if i == n + m - 1 { "\n" } else { " " });
    }
}
