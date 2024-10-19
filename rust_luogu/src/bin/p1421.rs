//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1421.rs
//@data      2023/11/30 19:07:39
//
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let (a, b): (i32, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let yv_money = a * 10 + b;
    println!("{}", yv_money / 19);
}
