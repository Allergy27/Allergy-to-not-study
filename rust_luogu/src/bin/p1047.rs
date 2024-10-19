use std::io;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let (m, n): (i32, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let mut qwq = [1; 10002];
    //下面是处理部分
    for _i in 0..=n - 1 {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();

        let mut nums = input.split_whitespace();
        let left: i32 = nums.next().unwrap().parse().unwrap();
        let right: i32 = nums.next().unwrap().parse().unwrap();

        for j in left..=right {
            qwq[j as usize] = 0;
        }
    }
    let count: i32 = qwq.iter().filter(|x| x == &&1).sum();
    println!("{}", m - 10001 + count);
}
