//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5711.rs
//@data      2023/12/04 16:40:07
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
    let year: i32 = input.trim().parse().unwrap();
    if year % 4 == 0 && year % 100 != 0 || year % 400 == 0 {
        println!("1");
    } else {
        println!("0");
    }
}
