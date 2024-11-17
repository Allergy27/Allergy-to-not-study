//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5731.rs
//@data      2023/12/20 14:57:14
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
    let mut qwq = vec![vec![0; n]; n];
    for i in 0..n / 2 {
        (i..n - 1 - i).for_each(|j| {
            qwq[i][j] = j + 4 * (n - i) * i + 1 - i;
            qwq[j][n - 1 - i] = j + 4 * (n - i) * i + n - 1 - 2 * i + 1 - i;
            qwq[n - 1 - i][n - 1 - j] = j + 4 * (n - i) * i + (n - 1 - 2 * i) * 2 + 1 - i;
            qwq[n - 1 - j][i] = j + 4 * (n - i) * i + (n - 1 - 2 * i) * 3 + 1 - i;
        });
    }
    if n % 2 == 1 {
        qwq[n / 2][n / 2] = n * n
    }
    (0..n).for_each(|x| {
        (0..n).for_each(|y| print!("{:3}", qwq[x][y]));
        println!()
    })
}
