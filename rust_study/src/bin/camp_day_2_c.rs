//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_2_c.rs
//@data      2024/11/17 13:48:19
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
const MOD: i64 = 998244353;
const ROOT: i64 = 3; // Primitive root of MOD

// Fast modular exponentiation
fn mod_exp(mut base: i64, mut exp: i64, modulus: i64) -> i64 {
    let mut result = 1;
    while exp > 0 {
        if exp % 2 == 1 {
            result = result * base % modulus;
        }
        base = base * base % modulus;
        exp /= 2;
    }
    result
}

// Perform the Number Theoretic Transform
fn ntt(a: &mut Vec<i64>, invert: bool) {
    let n = a.len();
    let mut j = 0;

    // Bit-reversal permutation
    for i in 1..n {
        let mut bit = n >> 1;
        while j & bit != 0 {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if i < j {
            a.swap(i, j);
        }
    }

    // Perform the NTT
    let mut len = 2;
    while len <= n {
        let wlen = if invert {
            mod_exp(ROOT, (MOD - 1) / len as i64, MOD)
        } else {
            mod_exp(ROOT, (MOD - 1) / len as i64, MOD)
        };
        for i in (0..n).step_by(len) {
            let mut w = 1;
            for j in 0..len / 2 {
                let u = a[i + j];
                let v = a[i + j + len / 2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = w * wlen % MOD;
            }
        }
        len *= 2;
    }

    // If inverting, divide by n
    if invert {
        let n_inv = mod_exp(n as i64, MOD - 2, MOD);
        for x in a.iter_mut() {
            *x = *x * n_inv % MOD;
        }
    }
}

// Multiply two polynomials using NTT
fn solve() {
    let n = cin!(usize);
    let mut a = cin!([i64; 1 << n]);
    let mut b = cin!([i64; 1 << n]);
    ntt(&mut a, false);
    ntt(&mut b, false);
    let mut c = vec![0; 1 << n];
    for i in 0..(1 << n) {
        c[i] = a[i] * b[i] % MOD;
    }
    ntt(&mut c, true);
    c.iter().for_each(|x| print!("{} ", x)); 
    println!(); // Add a newline
}