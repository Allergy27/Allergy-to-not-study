//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5727.rs
//@data      2023/12/15 21:12:25
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut n: i32 = input.trim().parse().unwrap();
    let mut qwq = vec![n];
    while n != 1 {
        match n % 2 {
            0 => n /= 2,
            1 => n = n * 3 + 1,
            _ => unreachable!(),
        }
        qwq.push(n);
    }
    qwq.iter().rev().for_each(|x| print!("{} ", x));
}
