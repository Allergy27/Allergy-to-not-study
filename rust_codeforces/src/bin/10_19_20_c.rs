//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_19_20_c.rs
//@data      2024/10/20 12:23:02
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let s = cin().chars().map(|s| s == '1').collect::<Vec<bool>>();
    let mut win = s[0] || s[n - 1];
    for i in 1..n {
        if s[i] && s[i - 1] {
            win = true;
            break;
        }
    }
    println!("{}", if win { "Yes" } else { "No" });
}
