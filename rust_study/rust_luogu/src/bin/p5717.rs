//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5717.rs
//@data      2023/12/04 18:31:04
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    for _ in 0..t {
        solve()
    }
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut qwq: Vec<i32> = input
        .trim()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    qwq.sort_unstable();
    let (a, b, c) = (qwq[0], qwq[1], qwq[2]);
    if a + b <= c {
        println!("Not triangle");
    } else {
        if a * a + b * b == c * c {
            println!("Right triangle")
        }
        if a * a + b * b > c * c {
            println!("Acute triangle")
        }
        if a * a + b * b < c * c {
            println!("Obtuse triangle")
        }
        if a == b || b == c {
            println!("Isosceles triangle")
        }
        if a == b && b == c {
            println!("Equilateral triangle")
        }
    }
}
