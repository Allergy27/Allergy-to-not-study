//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_984_div3_c.rs
//@data      2024/11/05 23:21:53
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
    let mut s = cin!().chars().collect::<Vec<_>>();
    let mut i = 3;
    let n = s.len();
    let mut cot = 0;
    let check = |s: &Vec<char>, i: usize| -> bool {
        i - 3 > 0 && i < n && s[i - 3..=i] == ['1', '1', '0', '0']
    };
    while i < n {
        if check(&s, i - 3) {
            cot += 1;
        }
        i += 1;
    }
    let m = cin!(usize);
    for _ in 0..m {
        let (a, b) = cin!(usize, char);
        let i = a - 1;
        let checkf = |s: &Vec<char>| (i - 3..i + 1).fold(true, |ans, i| ans & check(s, i));
        if checkf(&s) {
            cot -= 1;
        }
        s[i] = b;
        if checkf(&s) {
            cot += 1;
        }
        println!("{}", if cot > 0 { "YES" } else { "NO" });
    }
}
