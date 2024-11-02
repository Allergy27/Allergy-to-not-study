//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1031.rs
//@data      2024/10/28 21:27:28
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
    let n = cin().parse::<i64>().unwrap();
    let a = cin().split_whitespace().map(|s| s.parse::<i64>().unwrap()).collect::<Vec<_>>();
    let avg = a.iter().sum::<i64>() / n;
    let mut sum = 0;
    let mut ans = 0;
    for i in a {
        sum += i - avg;
        if sum != 0 {
            ans += 1;
        }
    }
    println!("{}", ans)
}
