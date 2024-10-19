//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace atcoder/qwq.rs
//@data      2024/10/12 20:01:27
use proconio::input;
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        n: usize,
        s:String,
    }
    let qwq = s.chars().collect::<Vec<char>>();
    let mut ans = 0;
    for i in 1..n - 1 {
        if qwq[i - 1] == '#' && qwq[i] == '.' && qwq[i + 1] == '#' {
            ans += 1;
        }
    }
    println!("{}", ans)
}
