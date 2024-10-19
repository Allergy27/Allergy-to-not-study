//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5735.rs
//@data      2024/04/15 13:14:38
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
   (0..t).for_each(|_| solve());
}
fn solve() {
    let dis = |x: (f64, f64), y: (f64, f64)| ((x.0 - y.0).powf(2.0) + (x.1 - y.1).powf(2.0)).sqrt();
    let mut s_all: Vec<(f64, f64)> = vec![(0.0,0.0);3];
    for s in &mut s_all {
        *s = cin()
            .split_whitespace()
            .fold((0.0, 0.0), |x, y| (x.1, y.parse::<f64>().unwrap()));
    }
    println!("{:.2}",dis(s_all[0],s_all[1])+dis(s_all[0],s_all[2])+dis(s_all[2],s_all[1]));
}