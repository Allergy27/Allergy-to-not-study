//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5718.rs
//@data      2023/12/04 20:40:33
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    for _ in 0..t {
        solve()
    }
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let qwq: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    println!("{}", *qwq[..].iter().min().unwrap());
}
