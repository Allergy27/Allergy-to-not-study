//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p2415.rs
//@data      2024/10/28 02:56:09
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let qwq = cin().split_whitespace().map(|s| s.parse().unwrap()).collect::<Vec<i64>>();
    let n = qwq.len() as i64 - 1;
    println!("{}", qwq.iter().sum::<i64>() << n)
}
