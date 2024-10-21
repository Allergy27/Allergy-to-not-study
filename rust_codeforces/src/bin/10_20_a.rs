//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10.20.a.rs
//@data      2024/10/20 17:05:34
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (a, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    if a > b {
        println!("{}", a);
        return;
    }
    println!("{}", if a * 2 > b { a * 2 - b } else { 0 });
}
