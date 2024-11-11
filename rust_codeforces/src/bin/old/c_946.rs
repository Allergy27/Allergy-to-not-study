//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace codeforces/c_946.rs
//@data      2024/07/12 14:28:18
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i128>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let mut qwq = std::collections::HashMap::<(i128, i128, i128), i128>::new();
    let nums = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i128>>();
    println!(
        "{}",
        (0..n - 2).fold(0, |mut ans, i| {
            let triple_tot = (nums[i], nums[i + 1], nums[i + 2]);
            let check_tot = vec![
                (0, nums[i + 1], nums[i + 2]),
                (nums[i], 0, nums[i + 2]),
                (nums[i], nums[i + 1], 0),
            ];
            for trip in check_tot {
                ans += qwq.get(&trip).unwrap_or(&0) - qwq.get(&triple_tot).unwrap_or(&0);
                qwq.insert(trip, qwq.get(&trip).unwrap_or(&0) + 1);
            }
            qwq.insert(triple_tot, qwq.get(&triple_tot).unwrap_or(&0) + 1);
            ans
        })
    )
}
