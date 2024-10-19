//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace rust_atcoder/c_10_19_c.rs
//@data      2024/10/19 20:51:58
use proconio::input;

fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        n:usize,
        mut a:[i32;n],
        mut b:[i32;n-1],
    }
    a.sort_unstable();
    b.sort_unstable();
    let mut ans = 0;
    let mut j = n - 2;
    let mut flag = true;
    for i in (0..n).rev() {
        if !flag && b[j] < a[i] {
            println!("-1");
            return;
        } else if b[j] < a[i] {
            ans = i;
            flag = false;
            continue;
        }
        j = j.saturating_sub(1);
    }
    println!("{}", a[ans]);
}
