use std::io;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let num: i128 = input.trim().parse().unwrap();
    if num == 1 {
        println!("{}", num);
    }
    for i in 2..=num {
        if num % i == 0 {
            println!("{}", num / i);
        }
    }
}
