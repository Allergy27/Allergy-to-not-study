//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1789.rs
//@data      2023/12/20 16:22:04
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let fire = [
        (-2, 0),
        (-1, -1),
        (-1, 0),
        (-1, 1),
        (0, -1),
        (0, 0),
        (0, 1),
        (0, 2),
        (1, 1),
        (1, 0),
        (1, -1),
        (2, 0),
        (0, -2),
    ];
    let stone = [
        (-2, -2),
        (-2, -1),
        (-2, 0),
        (-2, 1),
        (-2, 2),
        (-1, -2),
        (-1, -1),
        (-1, 0),
        (-1, 1),
        (-1, 2),
        (0, -2),
        (0, -1),
        (0, 0),
        (0, 1),
        (0, 2),
        (1, -2),
        (1, -1),
        (1, 0),
        (1, 1),
        (1, 2),
        (2, -2),
        (2, -1),
        (2, 0),
        (2, 1),
        (2, 2),
    ];
    let (n, m, k) = cin()
        .split_whitespace()
        .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));


    let mut qwq = vec![vec![false; n + 3]; n + 3];
    (0..m).for_each(|_| {
        let (a, b) = cin()
            .split_whitespace()
            .fold((0, 0), |x, y| (x.1, y.parse::<i32>().unwrap()));

        fire.iter()
            .for_each(|&x| qwq[f(a + x.0)][f(b + x.1)] = true);
    });
    (0..k).for_each(|_| {
        let (a, b) = cin()
            .split_whitespace()
            .fold((0, 0), |x, y| (y.parse::<i32>().unwrap(), x.0));

        stone
            .iter()
            .for_each(|&x| qwq[f(a + x.0)][f(b + x.1)] = true);
    });
    let ans = (1..=n).fold(0, |p, y| {
        p + (1..=n).fold(0, |q, x| q + if !qwq[y][x] { 1 } else { 0 })
    });
    println!("{}", ans);
}
fn f(k: i32) -> usize {
    if k > 0 { k as usize } else { 0 }
}
