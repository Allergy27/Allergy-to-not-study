//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace rust_atcoder/c_10_19_a.rs
//@data      2024/10/19 20:01:08
use proconio::input;

fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        n: usize,
        m: i32,
        a: [i32; n],
    }
    let mut last_get = a[0];
    let mut ans = 1;
    for &i in a.iter().skip(1) {
        if i - last_get >= m {
            last_get = i;
            ans += 1;
        }
    }
    println!("{}", ans);
}
