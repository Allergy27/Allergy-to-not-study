//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1420.rs
//@data      2023/12/15 20:05:35
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    println!("{}", input.trim().split_whitespace().map(|s| s.parse().unwrap()).fold((0, -1, 1), |x, y:i64| {(x.0.max(x.2 + (x.1 == y - 1) as i64),y,if x.1 == y - 1 { x.2 + 1 } else { 1 },)}).0);
}
