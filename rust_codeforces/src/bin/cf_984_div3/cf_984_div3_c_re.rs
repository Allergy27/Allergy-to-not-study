//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_984_div3_c_re.rs
//@data      2024/11/11 05:12:25
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
    let mut s = cin!().chars().collect::<Vec<char>>();
    let n = s.len();
    let mut ans = 0;
    for i in 0..n - 3 {
        if s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0' {
            ans += 1
        }
    }
    let q = cin!(usize);
    for _ in 0..q {
        let (i, b) = cin!(usize, char);
        let i = i - 1;
        if i + 3 < n && s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0'
            || i >= 1
                && i + 2 < n
                && s[i - 1] == '1'
                && s[i] == '1'
                && s[i + 1] == '0'
                && s[i + 2] == '0'
            || i >= 2
                && i + 1 < n
                && s[i - 2] == '1'
                && s[i - 1] == '1'
                && s[i] == '0'
                && s[i + 1] == '0'
            || i >= 3 && s[i - 3] == '1' && s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '0'
        {
            ans -= 1
        }
        s[i] = b;
        if i + 3 < n && s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0'
            || i > 0
                && i + 2 < n
                && s[i - 1] == '1'
                && s[i] == '1'
                && s[i + 1] == '0'
                && s[i + 2] == '0'
            || i >= 2
                && i + 1 < n
                && s[i - 2] == '1'
                && s[i - 1] == '1'
                && s[i] == '0'
                && s[i + 1] == '0'
            || i >= 3 && s[i - 3] == '1' && s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '0'
        {
            ans += 1
        }
        if ans > 0 {
            println!("YES")
        } else {
            println!("NO")
        }
    }
}
