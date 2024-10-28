//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p3397.rs
//@data      2024/10/28 03:16:54
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m) = cin().split_whitespace().fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = vec![vec![0; n + 2]; n + 2];
    for _ in 0..m {
        let all = cin().split_whitespace().map(|s| s.parse().unwrap()).collect::<Vec<usize>>();
        let (a, b, c, d) = (all[0], all[1], all[2], all[3]);
        //二维差分
        qwq[a][b] += 1;
        qwq[a][d + 1] -= 1;
        qwq[c + 1][b] -= 1;
        qwq[c + 1][d + 1] += 1;
    }
    for i in 1..=n {
        for j in 1..=n {
            qwq[i][j] += qwq[i - 1][j] + qwq[i][j - 1] - qwq[i - 1][j - 1];
            print!("{} ", qwq[i][j]);
        }
        println!();
    }

}
