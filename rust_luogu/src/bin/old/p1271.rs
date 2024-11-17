//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1271.rs
//@data      2024/01/17 19:03:38
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
    cin();
    let mut qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    qwq.sort_unstable();
    qwq.iter().for_each(|x| print!("{} ", x))
}
