//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_2_K.rs
//@data      2024/11/17 12:19:26
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

const MOD: u64 = 998244353;

// Fast exponentiation for modular arithmetic
fn mod_exp(base: u64, exp: u64, modulo: u64) -> u64 {
    let mut result = 1;
    let mut b = base % modulo;
    let mut e = exp;
    while e > 0 {
        if e % 2 == 1 {
            result = result * b % modulo;
        }
        b = b * b % modulo;
        e /= 2;
    }
    result
}

fn solve() {
    // Input reading
    let (n, k) = cin!(usize, usize);
    let a = cin!([u64; n]);
    // dp[xor_value] = count of subsequences with this XOR value
    let mut dp = std::collections::HashMap::new();
    dp.insert(0, 1); // Base case: empty subsequence with XOR = 0

    for &num in &a {
        let mut new_dp = dp.clone();
        for (&xor_value, &count) in &dp {
            let new_xor = xor_value ^ num;
            *new_dp.entry(new_xor).or_insert(0) += count;
            *new_dp.entry(new_xor).or_insert(0) %= MOD;
        }
        dp = new_dp;
    }
    // Count subsequences where XOR = 0 and length is divisible by k
    let mut result = 0;
    for l in (k..=n).step_by(k) {
        let comb = mod_exp(2, n as u64 - l as u64, MOD); // Choose subsequences
        if let Some(&count) = dp.get(&0) {
            result = (result + count * comb) % MOD;
        }
    }

    println!("{}", result);
}
