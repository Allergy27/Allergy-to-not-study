//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1923.rs
//@data      2024/01/17 20:05:47
fn cin() -> String {
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
    let (_, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    qwq.sort_unstable();
    println!("{}", qwq[b]);
}
