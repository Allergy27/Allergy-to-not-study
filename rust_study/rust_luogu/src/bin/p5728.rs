//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5728.rs
//@data      2023/12/18 21:08:48
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut qwq: Vec<Vec<i32>> = vec![vec![]; n];
    for i in 0..n {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        qwq[i] = input
            .trim()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let sum = qwq[i].iter().sum::<i32>();
        qwq[i].push(sum);
    }
    let ans = (0..n).fold(0, |x, i| {
        x+(i + 1..n).fold(0, |y, j| {
            if     -5 <= qwq[j][0]-qwq[i][0]
                && qwq[j][0]-qwq[i][0] <= 5
                && -5 <= qwq[j][1]-qwq[i][1]
                && qwq[j][1]-qwq[i][1] <= 5
                && -5 <= qwq[j][2]-qwq[i][2]
                && qwq[j][2]-qwq[i][2] <= 5
                && -10 <= qwq[j][3]-qwq[i][3]
                && qwq[j][3]-qwq[i][3] <= 10
            {
                y+1
            } else {
                y
            }
        })
    });
    println!("{}",ans);
}
