//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1028.rs
//@data      2024/10/28 18:57:29
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
    let n = cin().parse::<i64>().unwrap();

    let mut qwq = vec![1; n as usize + 1];
    for i in 1..=n {
        // if qwq[i as usize] == 0 {
        for j in 1..=i / 2 {
            qwq[i as usize] += qwq[j as usize]
        }
        // }
    }
    println!("{}", qwq[n as usize]);
}
