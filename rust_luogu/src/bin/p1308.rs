//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1308.rs
//@data      2023/12/21 19:29:17
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let aim = cin().trim().to_uppercase();
    let input = cin();
    let input =input[..input.len()-2].to_string()+" ";
    let qwq = input
        .chars()
        .enumerate()
        .fold((-1, 0, String::new()), |mut x, i| {
            if i.1 == ' ' {
                if x.2.to_uppercase() == aim {
                    x.1 += 1;
                    if x.0 == -1 {
                        x.0 = (i.0 - x.2.len()) as i32;
                    }
                }
                x.2 = String::new();
            } else {
                x.2 += &i.1.to_string();
            }
            x
        });
    if qwq.0 == -1 {
        println!("-1")
    } else {
        println!("{} {}", qwq.1, qwq.0)
    }
}
