//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5706.rs
//@data      2023/11/30 18:22:04
//
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let (cook_cola, class_mates): (f64, f64) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    println!("{:.3}\n{:.0}", cook_cola / class_mates, class_mates * 2.0);
}
