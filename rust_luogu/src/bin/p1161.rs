//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1161.rs
//@data      2023/12/20 14:17:45
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
    let n: usize = cin().parse().unwrap();
    let mut ans = 0;
    for _ in 0..n {
        let input = cin();
        let mut input = input.split_whitespace();
        let (a, t): (f64, usize) = (
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
        );
        (1..=t).for_each(|j| {
            ans ^= (j as f64 * a).floor() as i32; //关变开开变关
        });
    }
    println!("{}", ans);
}
