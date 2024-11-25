//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_381_b.rs
//@data      2024/11/22 20:05:15
#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    }};
    ([$type:ty;$n:expr]) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        let mut arr = Vec::with_capacity($n as usize);
        for _ in 0..$n {
            arr.push((s.next().unwrap()).parse::<$type>().unwrap());
        }
        arr
    }};
    ($type:ty) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        (s.next().unwrap()).parse::<$type>().unwrap()
    }};

    ($($type:ty),*) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        ($(s.next().unwrap().parse::<$type>().unwrap()),*)
    }}
}
fn main() {
    let t = 1;
    //let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut qwq = [0; 26];
    let s = cin!().bytes().collect::<Vec<u8>>();
    let n = s.len();
    if n & 1 != 0 {
        println!("No");
        return;
    }
    for i in (0..n).step_by(2) {
        if s[i] != s[i + 1] {
            println!("No");
            return;
        }
        qwq[(s[i] - b'a') as usize] += 2;
    }
    for &count in &qwq {
        if count != 0 && count != 2 {
            println!("No");
            return;
        }
    }
    println!("Yes");
}
