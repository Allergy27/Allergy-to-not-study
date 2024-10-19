//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p3954.rs
//@data      2023/11/30 19:10:01
//
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.trim().split_whitespace();
    let (a, b, c): (i32, i32, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    println!("{}", a * 2 / 10 + b * 3 / 10 + c / 2);
}
