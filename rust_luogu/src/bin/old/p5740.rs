//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p5740.rs
//@data      2024/10/27 20:52:17
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
    let n = cin().parse::<usize>().unwrap();
    let ans = (0..n).fold((String::new(), 0, 0, 0), |ans, _| {
        let input = cin();
        let mut cin = input.split_whitespace();
        let name = cin.next().unwrap().to_string();
        let a = cin.next().unwrap().parse::<i32>().unwrap();
        let b = cin.next().unwrap().parse::<i32>().unwrap();
        let c = cin.next().unwrap().parse::<i32>().unwrap();
        let sum = a + b + c;
        if sum > ans.1 + ans.2 + ans.3 || ans.0 == String::new() {
            (name, a, b, c)
        } else {
            ans
        }
    });
    println!("{} {} {} {}", ans.0, ans.1, ans.2, ans.3);
}
