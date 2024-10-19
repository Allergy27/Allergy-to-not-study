//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace atcoder/c_10_12_c.rs
//@data      2024/10/12 20:16:39
use ::proconio::input;
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        n:usize,
        d:[String;n],
    }
    let qwq = d
        .iter()
        .map(|x| x.chars().collect())
        .collect::<Vec<Vec<char>>>();
    let mut qaq = vec![vec![' '; n]; n];
    for i in 1..=n {
        for j in 1..=n {
            let q = i.min(j).min((n - i + 1).min(n - j + 1));
            let (mut a, mut b, mut c) = (i, j, i);
            for _ in 1..=q % 4 {
                a = b;
                b = n - c + 1;
                c = a;
            }
            qaq[a - 1][b - 1] = qwq[i - 1][j - 1];
        }
    }
    for x in qaq {
        println!("{}", x.iter().collect::<String>());
    }
}
