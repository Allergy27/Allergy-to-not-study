//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace bin/1669G.rs
//@data      2024/11/13 17:46:25
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
    let (n, m) = cin!(usize, usize);
    let mut qwq = Vec::with_capacity(n);
    for i in 0..n {
        qwq.push(cin!().chars().collect::<Vec<_>>());
    }
    for i in 0..m {
        let mut l = n as i32 - 1;
        for r in (0..n).rev() {
            if l == 0 {
                break;
            }
            if qwq[r][i] == 'o' {
                l = r as i32 - 1;
            } else if qwq[r][i] == '*' {
                let tmp = qwq[l as usize][i];
                qwq[l as usize][i] = '*';
                qwq[r][i] = tmp;
                l -= 1;
            }
        }
    }
    qwq.iter().for_each(|x| println!("{}", x.iter().collect::<String>()));
    println!();
}
