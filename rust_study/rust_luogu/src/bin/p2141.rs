//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p2141.rs
//@data      2023/12/20 13:12:03
use std::collections::HashSet;
fn input() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let n: usize = input().parse().unwrap();
    let qwq = input()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    let mut set: HashSet<i32> = HashSet::new();
    (0..n).for_each(|x| {
        (0..n).for_each(|y| {
            if y != x {
                set.insert(qwq[x] + qwq[y]);
            }
        })
    });
    let ans = (0..n).fold(0, |x, y| x + if set.contains(&qwq[y]) { 1 } else { 0 });
    println!("{}", ans);
}
