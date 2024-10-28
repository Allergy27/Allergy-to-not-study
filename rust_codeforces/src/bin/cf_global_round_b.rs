//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_global_round_b.rs
//@data      2024/10/27 23:01:13
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    // let t = 1;
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<usize>().unwrap();
    if n == 1 || n == 3 {
        println!("-1");
        return;
    }
    if n & 1 == 1 {
        for _ in 0..n - 4 {
            print!("3");
        }
        println!("6366")
    } else {
        for _ in 0..n - 2 {
            print!("3");
        }
        println!("66")
    }
}
