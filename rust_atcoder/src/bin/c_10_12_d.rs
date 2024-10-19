//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace atcoder/c_10_12_d.rs
//@data      2024/10/12 20:30:25
use ::proconio::input;
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        s: String
    }
    let mut qwq = vec![vec![]; 26];
    let s = s.chars().collect::<Vec<char>>();
    s.iter()
        .enumerate()
        .for_each(|(i, &x)| qwq[x as usize - 'A' as usize].push(i as i64));
    let mut ans = 0;
    for i in qwq {
        if i.len() < 2 {
            continue;
        }
        let mut x = i[0];
        let mut c = 1;
        for &j in i.iter().skip(1) {
            ans += (j - 1) * c - x;
            x += j;
            c += 1;
        }
    }
    println!("{}", ans);
}
