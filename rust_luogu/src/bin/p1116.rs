//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1116.rs
//@data      2024/01/20 14:56:46
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let mut qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    while qwq.len() < n {
        qwq.extend(cin().split_whitespace().map(|s| s.parse::<i32>().unwrap()))
    }
    let ans = (0..n).fold(0, |x, i| {
        x + (0..i).fold(0, |p, j| p + if qwq[i] < qwq[j] { 1 } else { 0 })
    });
    println!("{}", ans);
}
