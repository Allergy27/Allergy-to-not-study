//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace codeforces/test.rs
//@data      2024/07/12 18:18:12
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;//let t = cin().parse::<i32>().unwrap();
    let _ = (0..t).for_each(|_|solve());
}
fn solve() {
    println!("{}",42-24);
}