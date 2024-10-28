//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_24_e.rs
//@data      2024/10/24 23:37:40
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}

fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse::<usize>().unwrap() - 1)
        .collect::<Vec<_>>();
    let mut qaq = vec![false; n];
    let mut ans = 0;
    for i in 0..n {
        // 没判断过
        if !qaq[i] {
            let mut cnt = 0;
            let mut j = i;
            //只要没判断过就一直找下去
            while !qaq[j] {
                qaq[j] = true;
                j = qwq[j];
                cnt += 1;
            }
            println!("{:?}", qaq);
            ans += (cnt + 1) / 2 - 1
        }
    }
    println!("{}", ans)
}
