use std::io;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut nums = input.trim().split(' ');
    let a: i32 = nums.next().unwrap().parse().unwrap();
    let b: i32 = nums.next().unwrap().parse().unwrap();
    println!("{}", a + b);
}