//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1725.rs
//@data      2024/10/23 20:32:04
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}

fn solve() {
    let (n, l, r) = cin()
        .split_whitespace()
        .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    let mut dp = vec![i32::MIN; n * 2 + 1];
    dp[0] = 0;
    let mut mono = std::collections::VecDeque::new();
    mono.push_back(0);
    let mut ans = i32::MIN;
    for i in l..=n {
        //较小的尾部
        while !mono.is_empty() && dp[i - l] >= dp[*mono.back().unwrap()] {
            mono.pop_back();
        }
        mono.push_back(i - l);
        //加上r也到不了的
        while *mono.front().unwrap() + r < i {
            mono.pop_front();
        }
        dp[i] = dp[*mono.front().unwrap()] + qwq[i];
        if i + r > n {
            ans = ans.max(dp[i]);
        }
    }
    println!("{}", ans);
}
