//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p5744.rs
//@data      2024/10/28 03:04:45
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    // let t = 1;
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let input = cin();
    let mut iter = input.split_whitespace();
    let s = iter.next().unwrap();
    let a = iter.next().unwrap().parse::<i32>().unwrap();
    let b = iter.next().unwrap().parse::<i32>().unwrap();
    println!("{} {} {}", s, a + 1, (b + b / 5).min(600));
}
