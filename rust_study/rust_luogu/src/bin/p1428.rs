//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1428.rs
//@data      2023/12/15 21:23:27
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let qwq: Vec<i32> = input.trim().split_whitespace().map(|s| s.parse().unwrap()).collect();
    let _ = (0..n).scan(0, |_, y|Some((0..y).fold(0, |a, b| if qwq[b] < qwq[y] { a + 1 } else { a }))).for_each(|x| print!("{} ", x));
}
