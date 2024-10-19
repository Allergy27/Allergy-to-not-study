//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5707.rs
//@data      2024/04/15 16:21:39
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
        .fold((0, 0), |x, y| (x.1, y.parse::<i32>().unwrap()));
    let mut go_time = 470 - a / b - ((a % b > 0) as i32);
    go_time += if go_time < 0 { 1440 } else { 0 };
    println!("{:02}:{:02}", go_time / 60, go_time % 60);
}
