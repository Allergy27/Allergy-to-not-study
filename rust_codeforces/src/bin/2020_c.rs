//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/2020_c.rs
//@data      2024/10/26 14:42:27
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    // let t = 1;
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (mut a, mut b, mut c) = cin()
        .split_whitespace()
        .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<i64>().unwrap()));
    while a != 0 || b != 0 || c != 0 {
        if a == 0 {
            println!("1");
            a += 1;
        } else if b == 0 {
            println!("2");
            b += 1;
        } else if c == 0 {
            println!("3");
            c += 1;
        } else {
            let mut min = a;
            if b < min {
                min = b;
            }
            if c < min {
                min = c;
            }
            a -= min;
            b -= min;
            c -= min;
        }
    }
}
