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
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (a, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<i32>().unwrap()));
    let use_time = a.abs();
    if -use_time <= b - use_time + 1 {
        println!("YES");
    } else {
        println!("NO")
    }
}
