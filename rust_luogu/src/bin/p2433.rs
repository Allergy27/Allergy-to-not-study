use std::f32::consts::PI;

//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p2433.rs
//@data      2023/11/30 19:13:19
//
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let a: i32 = input.next().unwrap().parse().unwrap();
    let six: f32 = 6.0 * 6.0 + 9.0 * 9.0;
    let pi = PI as f64;
    match a {
        1 => println!("I love Luogu!"),
        2 => println!("{} {}", 6, 4),
        3 => println!("{}\n{}\n{}", 3, 12, 2),
        4 => println!("{:.3}", 500.0 / 3.0),
        5 => println!("{}", 15),
        6 => println!("{:.4}", six.sqrt()),
        7 => println!("{}\n{}\n{}", 110, 90, 0),
        8 => println!(
            "{:.4}\n{:.4}\n{:.3}",
            pi * 10.0,
            pi * 25.0,
            (4.0 / 3.0) * pi * 125.0
        ),
        9 => println!("{}", 22),
        10 => println!("{}", 9),
        11 => println!("{:.4}", 100.0 / 3.0),
        12 => println!("{}\nR", 13),
        13 => println!("{:.0}", f64::powf((4.0 / 3.0) * pi * 1064.0, 1.0 / 3.0)),
        14 => println!("{}", 50),
        _ => println!("qwq"),
    }
}
