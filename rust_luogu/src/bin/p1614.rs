//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1614.rs
//@data      2023/12/20 13:31:58
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
    let (n, m): (usize, usize) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let mut qwq = vec![];
    let ans = (0..n).fold((0, 0), |x, y| {
        qwq.push(cin().parse::<i32>().unwrap());
        (
            x.0 + if y >= m { qwq[y] - qwq[y - m] } else { qwq[y] },
            if y >= m { x.1.min(x.0) } else { x.0 + qwq[y] },
        )
    });
    println!("{}", ans.1);
}
