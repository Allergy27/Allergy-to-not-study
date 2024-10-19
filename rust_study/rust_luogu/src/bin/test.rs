//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/test.rs
//@data      2023/12/20 11:48:55
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (a, b, c) = cin()
        .split_whitespace()
        .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));
    println!("{} {} {}", a, b, c);
}
