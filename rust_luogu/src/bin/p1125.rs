//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1125.rs
//@data      2023/12/20 19:45:12
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
    let mut all = [0; 26];
    cin().chars().for_each(|x| all[x as usize - 97] += 1);
    let res = all
        .iter()
        .filter_map(|&x| if x != 0 { Some(x) } else { None });
    let ans = res.clone().max().unwrap() - res.min().unwrap();
    if is_prime(ans) {
        println!("Lucky Word\n{}", ans)
    } else {
        println!("No Answer\n0")
    };
}
fn is_prime(x: i32) -> bool {
    if x == 2 {
        return true;
    }
    for i in 2.. {
        if x % i == 0 || x < 1 {
            return false;
        }
        if i * i >= x {
            break;
        }
    }
    true
}
