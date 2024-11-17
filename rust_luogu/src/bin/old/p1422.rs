//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1422.rs
//@data      2023/12/04 18:51:17
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    for _ in 0..t {
        solve()
    }
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let cost: f64 = input.trim().parse().unwrap();
    let fee = if cost > 400.0 {
        (cost - 400.0) * 0.5663 + 250.0 * 0.4663 + 150.0 * 0.4463
    } else if cost > 150.0 {
        (cost - 150.0) * 0.4663 + 150.0 * 0.4463
    } else {
        cost * 0.4463
    };
    println!("{:.1}", fee);
}
