//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_2_I.rs
//@data      2024/11/17 12:15:36
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
fn solve() {
    const MOD: u32 = 998244353;
    let n = cin!(usize);
    let a = cin!([u32; n]);

    let max_xor = 1 << 17; // Maximum possible XOR value (100000 in binary has ~17 bits)
    let mut dp = vec![0u32; max_xor as usize];
    dp[0] = 1; // Base case: one way to form XOR 0 (empty set)

    for &val in &a {
        let mut new_dp = dp.clone();
        for x in 0..max_xor {
            new_dp[(x ^ val) as usize] = (new_dp[(x ^ val) as usize] + dp[x as usize]) % MOD;
        }
        dp = new_dp;
    }

    // Compute the number of valid ways
    let mut result = 0u32;
    for &count in &dp {
        result = (result + (count as u64 * count as u64 % MOD as u64) as u32) % MOD;
    }

    println!("{}", result);
}
