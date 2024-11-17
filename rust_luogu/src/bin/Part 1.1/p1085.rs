//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1085.rs
//@data      2023/12/04 18:16:32
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    for _ in 0..t {
        solve()
    }
}
fn solve() {
    let mut unhappiest = [1, 0];
    for i in 1..=7 {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut input = input.split_whitespace();
        let (a, b): (i32, i32) = (
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
        );
        if a + b > unhappiest[1] {
            unhappiest[1] = a + b;
            unhappiest[0] = i;
        }
    }
    if unhappiest[1] > 8 {
        println!("{}", unhappiest[0]);
    } else {
        println!("0");
    }
}
