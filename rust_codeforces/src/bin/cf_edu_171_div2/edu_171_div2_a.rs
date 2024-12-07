//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/edu_171_div2_a.rs
//@data      2024/10/28 22:36:00
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
    let (x, y, _) = cin()
        .split_whitespace()
        .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<i64>().unwrap()));
    let len = x.min(y);
    println!("0 0 {} {}", len, len);
    println!("{} 0 {} {}", x, x - len, len);
}
