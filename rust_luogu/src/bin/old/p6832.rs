//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p6832.rs
//@data      2024/10/23 20:21:30
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut qwq = [0; 26];
    let ans = cin().chars().fold(0, |ans, x| {
        qwq[x as usize - 97] += 1;
        ans.max(qwq[x as usize - 97])
    });
    println!("{}",ans)
}
