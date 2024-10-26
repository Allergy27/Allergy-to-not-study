//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_24_b.rs
//@data      2024/10/24 22:44:31
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
    let mut qwq = vec![Vec::with_capacity(n); n];
    for i in &mut qwq {
        *i = cin()
            .split_whitespace()
            .map(|s| s.parse::<i32>().unwrap())
            .collect();
    }
    let mut le = vec![0; 2 * n];
    for i in (0..n).rev() {
        for (j, x) in qwq.iter().take(n - i).enumerate() {
            le[i] = le[i].max(-x[i + j]);
        }
    }
    for i in 1..n {
        for (j, x) in qwq.iter().skip(i).take(n - i).enumerate() {
            le[n - 1 + i] = le[n - 1 + i].max(-x[j]);
        }
    }
    // println!("{:?}", le);
    println!("{}", le.iter().sum::<i32>());
}
