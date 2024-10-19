//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p4956.rs
//@data      2023/12/15 20:45:47
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: u32 = input.trim().parse().unwrap();
    let n = n / 364;
    if n <= 103 {
        println!("{}\n{}", n - 3, 1)
    } else {
        match n % 3 {
            0 => println!("{}\n{}", 99, (n - 99) / 3),
            1 => println!("{}\n{}", 100, (n - 100) / 3),
            2 => println!("{}\n{}", 98, (n - 98) / 3),
            _ => unreachable!(),
        }
    }
}
