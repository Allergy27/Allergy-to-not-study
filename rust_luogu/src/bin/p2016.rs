//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p2016.rs
//@data      2024/11/03 20:29:49
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
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m) = cin!(usize, usize);
    let mut arr = vec![(0, String::new()); n];
    for x in &mut arr {
        *x = cin!(usize, String);
    }
    let mut now = 0;
    for _ in 0..m {
        let (a, b) = cin!(usize, usize);
        if arr[now].0 ^ a == 0 {
            now = (now + n - b) % n;
        } else {
            now = (now + b) % n;
        }
    }
    println!("{}", arr[now].1);
}
