//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_985_glb_b.rs
//@data      2024/11/11 13:11:47
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
    let n = cin!(usize);
    let a = cin!().chars().collect::<Vec<_>>();
    let b = cin!().chars().collect::<Vec<_>>();
    let mut cot = [0, 0];
    for i in a {
        cot[(i as u8 - b'0') as usize] += 1;
    }
    for i in b {
        let tmp = (i as u8 - b'0') as usize;
        if cot[tmp] > 0 && cot[tmp ^ 1] > 0 {
            cot[tmp ^ 1] -= 1;
        } else {
            println!("NO");
            return;
        }
    }
    println!("YES");
}
