//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5703.rs
//@data      2023/11/30 18:01:14
//
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let (a, b): (i64, i64) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    println!("{}", a * b);
}
