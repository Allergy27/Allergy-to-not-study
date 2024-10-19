//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1888.rs
//@data      2023/12/04 19:41:36
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
        .trim()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    qwq.sort_unstable();
    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            return a;
        }
        return gcd(b, a % b);
    }
    println!(
        "{}/{}",
        qwq[0] / gcd(qwq[0], qwq[2]),
        qwq[2] / gcd(qwq[0], qwq[2])
    );
}
