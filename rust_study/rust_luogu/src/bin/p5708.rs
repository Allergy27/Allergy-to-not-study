//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5708.rs
//@data      2023/11/30 18:27:14
//
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.trim().split_whitespace();
    let (a, b, c): (f64, f64, f64) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let p = (a + b + c) / 2.0;
    println!("{:.1}", (p * (p - a) * (p - b) * (p - c)).sqrt());
}
