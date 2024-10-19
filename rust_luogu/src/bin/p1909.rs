//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1909.rs
//@data      2023/12/04 18:21:49
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
    let needed: f64 = input.trim().parse().unwrap();
    let mut min_cost: f64 = std::f64::INFINITY;
    for _ in 1..=3 {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut input = input.trim().split_whitespace();
        let (a, b): (f64, f64) = (
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
        );
        if (needed / a).ceil() * b < min_cost {
            min_cost = (needed / a).ceil() * b;
        }
    }
    println!("{:.0}", min_cost);
}
