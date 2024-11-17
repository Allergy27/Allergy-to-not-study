//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1424.rs
//@data      2023/12/04 19:16:24
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
    let (a, b): (i32, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let mut kilo = 0;
    kilo += (a + b - 1) / 7 * 1250
        + if (a + b - 1) % 7 < 6 {
            (a + b - 1) % 7 * 250
        } else {
            1250
        };
    if a < 6 {
        kilo -= (a - 1) * 250
    } else {
        kilo -= 1250;
    }
    println!("{}", kilo);
}
