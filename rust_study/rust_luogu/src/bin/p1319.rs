//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1319.rs
//@data      2023/12/20 17:27:53
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<usize>>();
    let n = qwq[0];
    let mut check = (0, 0);
    qwq.iter().skip(1).for_each(|x| {
        (0..*x).for_each(|_| {
            print!("{}", check.1);
            check.0 = (check.0 + 1) % n;
            if check.0 == 0 {
                println!("");
            }
        });
        check.1 = (check.1 + 1) % 2;
    });
}
