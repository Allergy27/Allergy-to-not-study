//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5710.rs
//@data      2024/04/15 16:41:29
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
    let n = cin().parse::<usize>().unwrap();
    let (a, b) = ((n & 1 != 1) as i32, (4 < n && n <= 12) as i32);
    println!("{} {} {} {}", a & b, a | b, a ^ b, (!a + 2) & (!b + 2));
}
