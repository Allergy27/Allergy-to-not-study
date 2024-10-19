//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace atcoder/p_10_13_321_a.rs
//@data      2024/10/13 09:47:59
use proconio::input;
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! { mut n:i32 }
    let mut ans = -1;
    while n != 0 {
        if n % 10 <= ans {
            println!("No");
            return;
        }
        ans = n % 10;
        n /= 10;
    }
    println!("Yes");
}
