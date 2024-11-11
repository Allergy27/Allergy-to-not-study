use std::usize;

//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_982_div2_d.rs
//@data      2024/11/11 07:51:29
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
    // let t = 1;
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m) = cin!(usize, usize);
    let a = cin!([usize; n]);
    let b = cin!([usize; m]);

    let mut nxt = vec![vec![0; m]; n];
    for k in 0..m {
        let (mut r, mut sum) = (0, 0);
        for i in 0..n {
            while r < n && sum <= b[k] {
                sum += a[r];
                r += 1;
            }
            nxt[i][k] = r;
            sum -= a[i];
        }
    }
    const INF: usize = 2_000_000_000;

    let mut dp = vec![vec![INF; m]; n + 1];
    dp[0][0] = 0;
    for k in 0..m {
        for i in 0..n {
            dp[nxt[i][k]][k] = dp[nxt[i][k]][k].min(dp[i][k] + m - k - 1);
            if k + 1 < m {
                dp[i][k + 1] = dp[i][k + 1].min(dp[i][k])
            }
        }
    }
    let mut ans = INF;
    for i in 0..m {
        ans = ans.min(dp[n][i])
    }
    if ans == INF {
        println!("-1")
    } else {
        println!("{}", ans)
    }
}
