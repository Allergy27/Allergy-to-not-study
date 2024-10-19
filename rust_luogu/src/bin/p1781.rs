//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1781.rs
//@data      2024/01/18 12:33:31
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //1let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n: usize = cin().parse().unwrap();
    let comp =
        |a: &String, b: &String| -> bool { a.len() > b.len() || a.len() >= b.len() && a > b };
    let (ans, ans_idx) = (1..=n).fold((String::new(), 0), |x, i| {
        let p = cin();
        if comp(&p, &x.0) {
            (p, i)
        } else {
            x
        }
    });
    println!("{}\n{}", ans_idx, ans)
}
