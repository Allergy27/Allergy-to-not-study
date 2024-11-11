//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_20_c.rs
//@data      2024/10/20 17:55:12
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
    let mut qwq = vec![(0, 0); n];
    for x in &mut qwq {
        *x = cin()
            .split_whitespace()
            .fold((0, 0), |x, y| (x.1, y.parse::<i64>().unwrap()));
    }
    qwq.sort_unstable_by(|&a, &b| {
        (a.0+a.1).cmp(&(b.0+b.1))
    });
    qwq.iter().for_each(|x| print!("{} {} ", x.0, x.1));
    println!();
}
