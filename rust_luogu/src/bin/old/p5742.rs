//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p5742.rs
//@data      2024/10/28 02:47:56
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
    let (_, b, c) =
        cin().split_whitespace().fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));
    if b * 7 + c * 3 >= 800 && b + c > 140 {
        println!("Excellent");
    } else {
        println!("Not excellent");
    }
}
