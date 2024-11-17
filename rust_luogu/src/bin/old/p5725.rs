//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5725.rs
//@data      2023/12/15 20:21:29
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    (1..=n * n).for_each(|x| {
        print!("{:02}", x);
        if x % n == 0 {
            println!()
        }
    });
    println!();
    (0..n).for_each(|x| {
        (0..n - x-1).for_each(|_| print!("  "));
        (1..=x+1).for_each(|y| print!("{:02}", x*(x+1)/2+y));
        println!();
    });
}
