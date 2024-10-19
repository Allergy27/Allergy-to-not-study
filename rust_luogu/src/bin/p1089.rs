//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1089.rs
//@data      2023/12/15 20:55:00
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut ans = (0, 0);
    for day in 1..=12 {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let n: i32 = input.trim().parse().unwrap();
        if ans.1 + 300 - n < 0 {
            println!("-{}", day);
            return;
        } else {
            ans.0 += (ans.1 + 300 - n) / 100;
            ans.1 = (ans.1 + 300 - n) % 100;
        }
    }
    println!("{}", ans.0 * 120+ans.1);
}
