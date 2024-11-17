//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_986_div2_a.rs
//@data      2024/11/10 23:34:59
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
    let (_, a, b) = cin!(usize, i64, i64);
    let s = cin!().chars().collect::<Vec<_>>();
    let mut tmp = (0, 0);

    for _ in 0..1000 {
        // 假设最多重复1000次
        for i in &s {
            match i {
                'N' => {
                    tmp.1 += 1;
                }
                'E' => {
                    tmp.0 += 1;
                }
                'S' => {
                    tmp.1 -= 1;
                }
                'W' => {
                    tmp.0 -= 1;
                }
                _ => unreachable!(),
            }
            if tmp == (a, b) {
                println!("YES");
                return;
            }
        }
    }
    println!("NO");
}
