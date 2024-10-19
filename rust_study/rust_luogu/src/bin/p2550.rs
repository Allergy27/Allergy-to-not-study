//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p2550.rs
//@data      2023/12/19 21:32:47
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut check = [false; 34];
    input
        .split_whitespace()
        .map(|s| s.parse::<usize>().unwrap())
        .for_each(|x| check[x] = true);
    let mut ans = [0; 8]; //如果是一张都没有还得加一
    for _ in 0..n {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        ans[7 - input.split_whitespace().fold(0, |x, y| {
            if check[y.parse::<usize>().unwrap()] {
                x + 1
            } else {
                x
            }
        })] += 1;
    }
    ans[..7].iter().for_each(|x| print!("{} ", x));
}
