//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5729.rs
//@data      2023/12/19 21:15:50
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let (a, b, c): (usize, usize, usize) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let mut qwq = vec![vec![vec![true; c]; b]; a];
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    for _ in 0..n {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut input = input.split_whitespace();
        let (a1, b1, c1, a2, b2, c2): (usize, usize, usize, usize, usize, usize) = (
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
        );
        (a1 - 1..a2).for_each(|a| {
            (b1 - 1..b2).for_each(|b| (c1 - 1..c2).for_each(|c| qwq[a][b][c] = false))
        });
    }
    let ans = (0..a).fold(0, |x, x1| {
        x + (0..b).fold(0, |y, y1| {
            y + (0..c).fold(0, |z, z1| if qwq[x1][y1][z1] { z + 1 } else { z })
        })
    });
    println!("{}", ans);
}
