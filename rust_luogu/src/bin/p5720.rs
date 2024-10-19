//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5720.rs
//@data      2023/12/04 21:08:13
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
    let num: i32 = input.trim().parse().unwrap();
    println!("{}", format!("{:b}", num).len());
}
