//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5721.rs
//@data      2023/12/04 21:11:57
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
    for i in 0..num {
        for j in 1..=num - i {
            print!(
                "{:02}",
                if i > 0 { i * num - i * (i - 1) / 2 } else { 0 } + j
            );
        }
        println!();
    }
}
