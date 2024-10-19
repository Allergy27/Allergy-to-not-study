//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5276.rs
//@data      2023/12/15 20:40:21
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: f64 = input.trim().parse().unwrap();
    input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let qwq = input
        .trim()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .fold((10, 0, 0), |x, y| (x.0.min(y), x.1.max(y), x.2 + y));
    println!("{:.2}", (qwq.2 - qwq.1 - qwq.0) as f64 / (n-2.0));
}
