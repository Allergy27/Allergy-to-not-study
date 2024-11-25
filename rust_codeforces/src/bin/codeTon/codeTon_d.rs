//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/codeTon_d.rs
//@data      2024/11/24 01:06:48
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
    let mut arr = cin!([i64; m]);
    arr.sort_unstable_by(|x, y| y.cmp(x));
    let mut qwq = vec![-1; n];
    let mut flag = true;
    let mut div = vec![Vec::new(); n + 1];
    for i in 1..=n {
        for j in (i..=n).step_by(i) {
            div[j].push(i);
        }
    }
    let gcd = |mut x: i32, mut y: i32| -> i32 {
        while y != 0 {
            let temp = y;
            y = x % y;
            x = temp;
        }
        x.abs() // 返回正的最大公约数
    };
    for i in 1..=n {
        for x in &arr {
            let mut tmp = true;
            for d in &div[i] {
                if (*d < i) && qwq[d - 1] != -1 && gcd(*x as _, qwq[d - 1]) == qwq[d - 1] {
                    tmp = false;
                    break;
                }
            }
            if tmp {
                qwq[i - 1] = *x as _;
                break;
            }
        }
        if qwq[i - 1] == -1 {
            flag = false;
            break;
        }
    }
    if flag {
        qwq.iter().for_each(|x| print!("{x} "));
        println!()
    } else {
        println!("-1")
    }
}
