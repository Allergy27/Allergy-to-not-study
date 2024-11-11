//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1906.rs
//@data      2024/10/28 18:07:34
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    cin();
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse::<i64>().unwrap())
        .collect::<Vec<_>>();
    let m = *qwq.iter().max().unwrap();
    let s = qwq.iter().sum::<i64>();
    println!("{}", if m > 2 * (s - m) { s - m } else { s / 3 })
}
