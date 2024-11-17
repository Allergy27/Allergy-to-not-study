//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_380_d.rs
//@data      2024/11/16 20:23:48
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
    let s = cin!().bytes().collect::<Vec<_>>();
    let n = s.len() as i64;
    let m = cin!(i64);
    let q = cin!([i64; m]);
    let cot = |x: i64| {
        let mut p = x;
        let mut ans = 0;
        while p > 0 {
            ans += p & 1;
            p >>= 1;
        }
        ans
    };
    for x in q {
        let tmp = (x - 1) % n;
        let ck = (x - 1) / n;
        if (cot(ck) & 1) == 0 {
            print!("{} ", s[tmp as usize] as char);
        } else {
            print!("{} ", (s[tmp as usize] ^ 32) as char);
        }
    }
    println!()
}
