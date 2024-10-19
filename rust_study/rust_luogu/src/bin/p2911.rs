//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p2911.rs
//@data      2023/12/20 14:02:48
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let input = cin();
    let mut input = input.split_whitespace();
    let (a, b, c): (usize, usize, usize) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let mut qwq = vec![0; a + b + c + 1];
    (1..=a).for_each(|i| {
        (1..=b).for_each(|j| {
            (1..=c).for_each(|k| {
                qwq[i + j + k] += 1;
            })
        })
    });
    let ans = (3..=a + b + c).fold(0, |x, y| if qwq[x] >= qwq[y] { x } else { y });
    println!("{}", ans);
}
