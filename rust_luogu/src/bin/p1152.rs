//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1152.rs
//@data      2024/01/20 15:16:38
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
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    let mut qvq = (2..qwq.len())
        .map(|x| (qwq[x] - qwq[x - 1]).abs())
        .collect::<Vec<_>>();
    qvq.sort_unstable();
    if Vec::from_iter(1..=qvq.len() as i32).eq(&qvq) {
        println!("Jolly")
    } else {
        println!("Not jolly")
    }
}
