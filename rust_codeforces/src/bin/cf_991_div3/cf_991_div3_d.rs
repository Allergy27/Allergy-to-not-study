//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_991_div3_d.rs
//@data      2024/12/05 23:15:04
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
    // let t = 1;
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut s = cin!().bytes().collect::<Vec<u8>>();
    let n = s.len();

    for i in 1..n {
        let x = s[i] - b'0';
        for j in 1..x as usize {
            if i >= j && i + 1 < n + j && s[i - j] + 1 < s[i - j + 1] {
                s.swap(i - j, i - j + 1);
                s[i - j] -= 1;
            } else {
                break;
            }
        }
    }
    s.iter().for_each(|x| print!("{}", *x as char));
    println!()
}
