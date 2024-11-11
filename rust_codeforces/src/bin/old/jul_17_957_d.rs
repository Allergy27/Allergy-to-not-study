//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace codeforces/jul_17_957_d.rs
//@data      2024/07/17 14:29:03
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m, k) = cin()
        .split_whitespace()
        .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));
    let road = cin().chars().collect::<Vec<char>>();
    let mut dp = vec![-1; n + 2];
    dp[0] = k as i32;
    for i in 1..=n + 1 {
        if i != n + 1 && road[i - 1] == 'C' {
            continue;
        }
        for k in 1..=m {
            if i >= k && (i == k || road[i - k - 1] == 'L') {
                dp[i] = dp[i].max(dp[i - k])
            }
        }
        if i > 1 && road[i - 2] == 'W' {
            dp[i] = dp[i].max(dp[i - 1] - 1)
        }
    }
    println!("{}", if dp[n + 1] >= 0 { "YES" } else { "NO" })
}
