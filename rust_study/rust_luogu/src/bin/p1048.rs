use std::io::stdin;
fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let (t, m): (usize, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let mut dp = vec![0; t + 1];
    for _ in 0..m {
        let mut input = String::new();
        stdin().read_line(&mut input).unwrap();
        let mut input = input.split_whitespace();
        let (w, v): (usize, i32) = (
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
        );
        for j in (w..=t).rev() {
            dp[j] = std::cmp::max(dp[j], dp[j - w] + v);
        }
    }
    println!("{}", dp[t]);
}
