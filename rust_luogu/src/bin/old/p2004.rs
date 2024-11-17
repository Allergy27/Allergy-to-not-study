//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p2004.rs
//@data      2024/01/19 15:21:55
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (a, b, c) = cin()
        .split_whitespace()
        .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));
    let mut qwq = Vec::new();
    let mut f = vec![vec![0; b + 1]; a + 1];
    for i in 1..=a {
        qwq.push(
            cin()
                .split_whitespace()
                .map(|s| s.parse().unwrap())
                .collect::<Vec<i64>>(),
        );
        for j in 1..=b {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + qwq[i - 1][j - 1];
        }
    }
    let mut ans = (0, 0, 0);
    for i in c..=a {
        for j in c..=b {
            if f[i][j] - f[i - c][j] - f[i][j - c] + f[i - c][j - c] > ans.0 {
                ans = (f[i][j] - f[i - c][j] - f[i][j - c] + f[i - c][j - c], i - c + 1, j - c + 1);
            }
        }
    }
    println!("{} {}", ans.1, ans.2)
}
