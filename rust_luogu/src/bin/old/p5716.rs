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
    let qwq = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let (year, month): (i32, usize) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    if month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        println!("{}", 29);
    } else {
        println!("{}", qwq[month - 1]);
    }
}
