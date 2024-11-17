//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_988_div3_e.rs
//@data      2024/11/17 23:31:06
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
    let query = |l: usize, r: usize| {
        println!("? {} {}", l + 1, r + 1);
        std::io::Write::flush(&mut std::io::stdout()).unwrap();
        cin!(i64)
    };
    let mut qwq = Vec::new();
    let mut zro = -1;
    for i in 1..n {
        let x = query(0, i);
        if zro == -1 {
            if x != 0 {
                qwq.resize((i as i64 - x) as usize, 1);
                qwq.resize(i, 0);
                zro = x;
                qwq.push(1);
            }
        } else if x == zro {
            qwq.push(0);
        } else {
            zro = x;
            qwq.push(1);
        }
    }
    if zro != -1 {
        print!("! ");
        qwq.iter().for_each(|&x| print!("{}", x));
        println!()
    } else {
        println!("! IMPOSSIBLE")
    }
}
