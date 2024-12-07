//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_991_div3_c.rs
//@data      2024/12/05 22:45:54
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
    let s = cin!();
    let n = s.len();
    let qwq = s.bytes().map(|x| (x - b'0') as i64).collect::<Vec<_>>();
    let mut ans = 0;
    let mut num2 = 0;
    let mut num3 = 0;
    (0..n).for_each(|i| {
        if qwq[i] == 2 {
            num2 += 1;
        } else if qwq[i] == 3 {
            num3 += 1;
        }
        ans += qwq[i];
        ans %= 9;
    });
    let mut flag = false;
    for i in 0..=num2.min(9) {
        for j in 0..=num3.min(6) {
            if (ans + i * 2 + j * 6) % 9 == 0 {
                flag = true;
                break;
            }
        }
        if flag {
            break;
        }
    }
    if flag {
        println!("YES");
    } else {
        println!("NO");
    }
}
