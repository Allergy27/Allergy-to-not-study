//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5719.rs
//@data      2023/12/04 20:50:51
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
    let mut input = input.split_whitespace();
    let (a, b): (i32, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let m = (b * ((a / b) * (a / b + 1) / 2)) as f64;
    let n = (a * (a + 1) / 2 - m as i32) as f64;
    println!("{:.1} {:.1}", m / (a / b) as f64, n / (a - a / b) as f64);
}
