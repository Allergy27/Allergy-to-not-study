//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_26_d.rs
//@data      2024/10/26 20:33:56
use proconio::input;

fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        n:usize,
        m:usize,
        qwq:[(usize,usize);n],
    }
    let mut rmin = vec![m + 1; m + 2];
    for &(l, r) in &qwq {
        rmin[l] = rmin[l].min(r);
    }
    for i in (0..m).rev() {
        rmin[i] = rmin[i].min(rmin[i + 1]);
    }
    let mut ans = 0;

    for (l, &r) in rmin.iter().enumerate().skip(1).take(m) {
        let cot = 0.max(r - l);
        ans += cot;
    }
    println!("{}", ans);
}
