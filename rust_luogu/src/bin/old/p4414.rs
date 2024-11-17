//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p4414.rs
//@data      2023/12/04 19:53:31
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
    let mut qwq: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    qwq.sort_unstable();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    for i in input.chars() {
        if i == 'A' {
            print!("{} ", qwq[0])
        } else if i == 'B' {
            print!("{} ", qwq[1])
        } else if i == 'C' {
            print!("{} ", qwq[2])
        }
    }
}
