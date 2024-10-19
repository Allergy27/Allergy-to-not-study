//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1425.rs
//@data      2023/11/30 19:01:59
//
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let (a, b, c, d): (i32, i32, i32, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let swim_time = c * 60 - a * 60 + d - b;
    println!("{} {}", swim_time / 60, swim_time % 60);
}
