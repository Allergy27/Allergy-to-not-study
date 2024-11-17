//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1042.rs
//@data      2024/11/03 18:37:35
#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        loop{
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.to_string();
            }
        }
    }};
    ([$type:ty;$n:expr]) => {{
        let mut input = String::new();
        let mut s = loop{
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        let mut arr: [$type; $n] = Default::default();
        for x in arr.iter_mut() {
            *x = s.next().unwrap().parse::<$type>().unwrap();
        }
        arr
    }};
    ($type:ty) => {{
        let mut input = String::new();
        let mut s = loop{
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
    let s = cin!([String; 2]);
    println!("{:?}", s);
    let mut qwq = Vec::new();
    let mut f = true;
    while f {
        for x in cin!().chars() {
            if x == 'E' {
                f = false;
                break;
            }
            qwq.push(x);
        }
    }
    let n = qwq.len();
    let check = |score: usize| {
        if n == 0 {
            println!("{}:{}", 0, 0);
            return;
        }
        let mut i = 0;
        let mut f = false;
        while i < n || f {
            let mut w = 0;
            let mut l = 0;
            loop {
                if i >= n {
                    f = false;
                    break;
                }
                if qwq[i] == 'W' {
                    w += 1;
                } else {
                    l += 1;
                }
                i += 1;
                if (w >= score || l >= score) && w.abs_diff(l) >= 2 {
                    f = true;
                    break;
                }
            }
            println!("{}:{}", w, l);
        }
    };
    check(11);
    println!();
    check(21);
}
