//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace codeforces/aug_27_169_d.rs
//@data      2024/08/27 11:56:40
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
    let tran: std::collections::HashMap<&str, i32> = vec![("B", 1), ("G", 2), ("Y", 3), ("R", 4)]
        .into_iter()
        .collect();
    let (a, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let qwq = cin()
        .split_whitespace()
        .map(|s| tran[&s[0..1]] * tran[&s[1..2]] + 8)
        .collect::<Vec<i32>>();
    print!("{}", qwq[0])
}
