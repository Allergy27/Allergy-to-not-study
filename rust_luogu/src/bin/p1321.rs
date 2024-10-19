//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1321.rs
//@data      2023/12/22 19:54:17
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
    let mut input = cin().chars().filter(|x| x != &'.').collect::<Vec<char>>();
    (0..5).for_each(|_| input.push('.'));
    let (mut b, mut g) = (0, 0);
    for i in 0..=input.len()-4 {
        if input[i] == 'b' || input[i + 1] == 'o' || input[i + 2] == 'y' {
            b += 1
        } else if input[i] == 'g'
            || input[i + 1] == 'i'
            || input[i + 2] == 'r'
            || input[i + 3] == 'l'
        {
            g += 1
        }
    }
    println!("{}\n{}",b,g);
}

fn _match_string(input: String, target: String) -> String {
    input
        .chars()
        .fold((String::new(), String::new()), |x, y| {
            let r = x.1.clone() + &y.to_string();
            if r == target {
                (x.0, String::new())
            } else if r == &target[..r.len()] {
                (x.0, r)
            } else {
                (x.0 + &r, String::new())
            }
        })
        .0
}
