//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p2660.rs
//@data      2024/04/15 18:42:12
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let (a, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<i64>().unwrap()));
    let (mut x, mut y) = (a.max(b), a.min(b));
    let mut ans = 0;
    while y != 0 && x != 0 {
        (x, y) = (y, x);
        ans += 4 * x * (y / x);
        y %= x;
    }
    println!("{ans}");
}
