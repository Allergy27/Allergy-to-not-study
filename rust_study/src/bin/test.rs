//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/test.rs
//@data      2024/09/22 17:40:39
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (a, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    println!("{}", a + b);
}
