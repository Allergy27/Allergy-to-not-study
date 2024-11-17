//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p5587.rs
//@data      2024/11/16 02:23:14
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
    // let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let get_in = || {
        let mut tmp = Vec::new();
        loop {
            let input = cin!();
            if input == "EOF" {
                break;
            }
            tmp.push(input.chars().fold(String::new(), |mut ans, x| {
                if x == '<' {
                    ans.pop();
                } else {
                    ans.push(x);
                }
                ans
            }))
        }
        tmp
    };
    let mut ans = 0;
    let qwq = get_in();
    let qaq = get_in();
    for (a, b) in qwq.iter().zip(qaq.iter()) {
        ans += a.chars().zip(b.chars()).map(|(x, y)| (x == y) as i32).sum::<i32>();
    }
    let t = cin!(f64);
    println!("{:.0}", ans as f64 * 60.0 / t);
}
