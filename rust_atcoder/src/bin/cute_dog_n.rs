//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace atcoder/cute_dog_n.rs
//@data      2024/10/12 22:21:28
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
    let a = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    println!("{}", a.partition_point(|&x| x < 30));
}
