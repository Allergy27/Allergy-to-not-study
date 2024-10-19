//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p3741.rs
//@data      2023/12/22 19:03:37
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    cin();
    let input = cin();
    let ans = input.chars().fold((0, 0, 0, ' '), |x, y| {
        if x.1 == 1 || x.1 == 2 {
            let q = if y == 'K' { 1 } else { 0 };
            (
                x.0 + q,
                if q == 1 { 3 } else { 2 },
                if x.1 == 2 && q == 0 { 1 } else { x.2 },
                y,
            )
        } else {
            (
                x.0,
                if y == 'V' { 1 } else { 0 },
                if x.1 == 0 && y == 'K' && x.2 == 0 && x.3 == 'K' {
                    1
                } else {
                    x.2
                },
                y,
            )
        }
    });
    println!(
        "{}",
        ans.0 + ans.2 + if ans.2 == 0 && ans.1 == 2 { 1 } else { 0 }
    );
}
