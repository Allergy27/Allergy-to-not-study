//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/5c.rs
//@data      2024/11/11 11:06:06
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
    //let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let s = cin!();
    let mut st = Vec::new();
    let n = s.len();
    let mut qwq = vec![false; n];
    for (i, x) in s.chars().enumerate() {
        if x == '(' {
            st.push(i)
        } else if let Some(top) = st.pop() {
            //将匹配的两个标1
            qwq[top] = true;
            qwq[i] = true;
        }
    }
    let mut cot = 0;
    let mut mx = 0;
    let mut mp = std::collections::HashMap::new();
    for ck in qwq {
        if ck {
            cot += 1;
            continue;
        } else if cot >= mx {
            mx = cot;
            *mp.entry(mx).or_insert(0) += 1;
        }
        cot = 0;
    }
    if cot >= mx {
        mx = cot;
        *mp.entry(mx).or_insert(0) += 1;
    }
    if mx == 0 {
        //特判 0 1
        println!("0 1");
    } else {
        println!("{} {}", mx, mp.get(&mx).unwrap())
    }
}
