//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1059.rs
//@data      2024/01/17 23:35:08
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
    let mut n: usize = cin().parse().unwrap();
    let mut ans = vec![false; 2799];
    cin().split_whitespace().for_each(|x| {
        let i = x.parse::<usize>().unwrap();
        if ans[i] {
            n -= 1;
        } else {
            ans[i] = true
        };
    });
    println!("{}", n);
    ans.iter().enumerate().for_each(|(i, &x)|if x {print!("{} ", i)});
}
