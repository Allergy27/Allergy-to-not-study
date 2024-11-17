//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1022.rs
//@data      2023/12/21 16:13:30
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
    let mut num = String::new();
    let (mut neg, mut dd) = (false, false);
    let (mut xnum, mut cnum) = (0, 0);
    let mut ch = String::new();
    cin().chars().for_each(|x: char| {
        if x.is_ascii_digit() {
            num.push(x);
        } else if x.is_ascii_lowercase() {
            xnum += if !num.is_empty() {
                num.parse::<i32>().unwrap() * if neg { -1 } else { 1 }
            } else if neg {
                -1
            } else {
                1
            };
            ch = x.to_string();
            num.clear();
            neg = dd;
        } else if x == '=' {
            cnum += if !num.is_empty() {
                num.parse::<i32>().unwrap() * if neg { -1 } else { 1 }
            } else {
                0
            };
            num.clear();
            dd = true;
            neg = dd;
        } else {
            cnum += if !num.is_empty() {
                num.parse::<i32>().unwrap() * if neg { -1 } else { 1 }
            } else {
                0
            };
            num.clear();
            neg = if x == '-' { !dd } else { dd };
        }
    });
    cnum += if !num.is_empty() {
        num.parse::<i32>().unwrap() * if neg { -1 } else { 1 }
    } else {
        0
    };
    if cnum == 0 {
        println!("0.000")
    } else {
        println!("{}={:.3}", ch, -cnum as f64 / xnum as f64)
    };
}
