//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace atcoder/c_10_12_b.rs
//@data      2024/10/12 20:05:47
use proconio::input;
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        n: usize,
        d: [(f64,f64);n],
    }
    let ans = d.iter().fold((0f64, 0f64, 0f64), |ans, &(x, y)| {
        (
            x,
            y,
            ans.2 + ((ans.0 - x).powi(2) + (ans.1 - y).powi(2)).sqrt(),
        )
    });
    let ans = ans.2 + ((ans.0).powi(2) + (ans.1).powi(2)).sqrt();
    println!("{}", ans);
}
