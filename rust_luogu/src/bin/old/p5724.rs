//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5724.rs
//@data      2023/12/15 19:58:07
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let qwq = input.split_whitespace().map(|s| s.parse().unwrap()).fold((0, 1001), |x, i| (x.0.max(i), x.1.min(i)));
    println!("{}",qwq.0-qwq.1);
}
