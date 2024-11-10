//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/11_10_4.rs
//@data      2024/11/10 10:48:56
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
}

struct Solution;
impl Solution {
    pub fn count_k_reducible_numbers(s: String, k: i32) -> i32 {
        let n = s.len();
        let bitc = |x: usize| {
            let mut cnt = 0;
            let mut x = x;
            while x > 0 {
                cnt += x & 1;
                x >>= 1;
            }
            cnt
        };
        let mut dp = vec![0; n + 1];
        let mut pre = vec![0; n + 1];
        for i in 2..=n {
            pre[i] = pre[bitc(i)] + 1;
        }
        const MOD: usize = 1_000_000_007;
        let s = s.as_bytes();
        let mut cur = 0;
        for i in 0..n {
            for j in (0..i).rev() {
                dp[j + 1] += dp[j];
                dp[j] %= MOD;
            }
            if s[i] == b'1' {
                dp[cur] += 1;
                dp[cur] %= MOD;
            }
            cur += (s[i] - b'0') as usize;
        }
        let mut ans = 0;
        for i in 0..=n {
            if pre[i] < k as usize {
                ans += dp[i];
            }
        }
        ((ans - 1) % MOD) as i32
    }
}
