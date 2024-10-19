//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1055.rs
//@data      2023/12/04 19:59:27
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
    let qwq: String = input.trim().split("-").collect();
    let mut res = 0;
    for (i, j) in qwq[..9].chars().enumerate() {
        res += (j as i32 - '0' as i32) * (i as i32 + 1);
    }
    let code = if res % 11 == 10 {
        "X".to_string()
    } else {
        format!("{}", res % 11)
    };
    if qwq[9..10] == code {
        println!("Right");
    } else {
        let qwq = input[..12].to_string() + &code;
        println!("{}", qwq);
    }
}
