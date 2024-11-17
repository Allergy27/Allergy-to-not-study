//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p2676.rs
//@data      2024/01/18 12:55:32
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
    let (a, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = Vec::new();
    (0..a).for_each(|_| qwq.push(cin().parse::<usize>().unwrap()));
    qwq.sort_unstable_by(|a, b| b.cmp(a));
    let mut ans = 0;
    for (i, &value) in qwq.iter().enumerate() {
        ans += value;
        if ans >= b {
            println!("{}", i + 1);
            break;
        }
    }
}
