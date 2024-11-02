//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_edu_round_d.rs
//@data      2024/10/28 15:05:11
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    // let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (_, m) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut dp = vec![0; m + 1];
    let mut check = vec![0; m + 2];
    let mut cnt = 0;
    cin().split_whitespace().for_each(|x| {
        let x = x.parse::<i64>().unwrap();
        match x.cmp(&0) {
            std::cmp::Ordering::Equal => {
                cnt += 1;
                let mut sum = 0;
                for i in 0..=m {
                    sum += check[i];
                    dp[i] += sum;
                }
                check = vec![0; m + 2];
                for i in (1..=cnt).rev() {
                    dp[i] = dp[i].max(dp[i - 1])
                }
            }
            std::cmp::Ordering::Greater => {
                if x <= cnt as i64 {
                    check[x as usize] += 1;
                    check[cnt + 1] -= 1;
                }
            }
            std::cmp::Ordering::Less => {
                if -x <= cnt as i64 {
                    check[0] += 1;
                    check[(cnt as i64 + x + 1) as usize] -= 1;
                }
                // println!("{:?}", check);
            }
        }
    });
    let mut sum = 0;
    for i in 0..=m {
        sum += check[i];
        dp[i] += sum;
    }
    println!("{}", dp.iter().max().unwrap_or(&0))
}
