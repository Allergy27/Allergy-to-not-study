//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5715.rs
//@data      2023/12/04 18:07:36
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
    let mut input = input.trim().split_whitespace();
    let (a, b, c): (i32, i32, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let mut qwq = vec![a, b, c];
    qwq.sort_unstable();
    println!("{} {} {}", qwq[0], qwq[1], qwq[2]);
}
