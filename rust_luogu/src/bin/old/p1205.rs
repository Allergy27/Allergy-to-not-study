//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1205.rs
//@data      2023/12/20 18:30:06
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
    let n: usize = cin().parse().unwrap();
    let mut qwq = vec![];
    (0..n).for_each(|_| qwq.push(cin().chars().collect()));
    let mut qaq = vec![];
    (0..n).for_each(|_| qaq.push(cin().chars().collect()));
    if check1(&qwq, &qaq) {
        println!("1")
    } else if check2(&qwq, &qaq) {
        println!("2")
    } else if check3(&qwq, &qaq) {
        println!("3")
    } else if check4(&qwq, &qaq) {
        println!("4")
    } else if check5(&qwq, &qaq) {
        println!("5")
    } else if check6(&qwq, &qaq) {
        println!("6")
    } else {
        println!("7")
    }
}

fn check1(a: &[Vec<char>], b: &[Vec<char>]) -> bool {
    (0..a.len()).fold(true, |x, y| {
        (0..a.len()).fold(true, |m, n| (a[y][n] == b[n][b.len() - 1 - y]) && m) && x
    })
}
fn check2(a: &[Vec<char>], b: &[Vec<char>]) -> bool {
    (0..a.len()).fold(true, |x, y| {
        (0..a.len()).fold(true, |m, n| {
            (a[y][n] == b[b.len() - 1 - y][b.len() - 1 - n]) && m
        }) && x
    })
}
fn check3(a: &[Vec<char>], b: &[Vec<char>]) -> bool {
    (0..a.len()).fold(true, |x, y| {
        (0..a.len()).fold(true, |m, n| (a[y][n] == b[b.len() - 1 - n][y]) && m) && x
    })
}
fn check4(a: &[Vec<char>], b: &[Vec<char>]) -> bool {
    (0..a.len()).fold(true, |x, y| {
        (0..a.len()).fold(true, |m, n| (a[y][n] == b[y][b.len() - 1 - n]) && m) && x
    })
}
fn check5(a: &[Vec<char>], b: &[Vec<char>]) -> bool {
    let a = a
        .iter()
        .map(|x| x.iter().rev().copied().collect::<Vec<char>>())
        .collect::<Vec<Vec<char>>>();
    check1(&a, b) || check2(&a, b) || check3(&a, b) || check6(&a, b)
}
fn check6(a: &[Vec<char>], b: &[Vec<char>]) -> bool {
    (0..a.len()).fold(true, |x, y| {
        (0..a.len()).fold(true, |m, n| (a[y][n] == b[y][n]) && m) && x
    })
}
