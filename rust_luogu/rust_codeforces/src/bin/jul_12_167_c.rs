//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace codeforces/jul_12_167_a.rs
//@data      2024/07/12 20:55:11
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let a = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    let b = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    let (mut x, mut y) = (0, 0);
    let (mut pos, mut neg) = (0, 0);
    for i in 0..n {
        if a[i] > b[i] {
            x += a[i]
        } else if a[i] < b[i] {
            y += b[i]
        } else {
            neg += (a[i] < 0) as i32;
            pos += (a[i] > 0) as i32;
        }
    }
    println!(
        "{}",
        (-neg..=pos).fold(-1e9 as i32, |ans, i| {
            ans.max((x + i).min(y + pos - neg - i))
        })
    )
}
