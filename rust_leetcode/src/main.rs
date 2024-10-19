fn main() {
    println!("Hello, world!");
    let qwq: Vec<i32> = vec![1, 2, 3, 4, 5, 6, 7];
    let p = { *qwq[1..5].iter().min().unwrap() };
    println!("{}", p);
}
