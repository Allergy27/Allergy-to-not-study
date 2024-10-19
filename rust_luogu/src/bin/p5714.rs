//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5714.rs
//@data      2023/12/04 16:51:58
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
    let (m, h): (f64, f64) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let bmi = m / (h * h);
    if bmi < 18.5 {
        println!("Underweight");
    } else if bmi < 24.0 {
        println!("Normal");
    } else {
        let bmi = (bmi * 10000.0).round() / 10000.0;
        let bmi_count: Vec<char> = bmi.to_string().chars().collect();
        let mut bmi = String::new();
        bmi.extend(bmi_count);
        println!("{}", bmi);
        println!("Overweight");
    }
}
