//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace bin/C_Skill_Up.rs
//@data      2024/11/13 18:32:46
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
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m, x) = cin!(usize, usize, usize);
    let mut qwq = Vec::with_capacity(n);
    for _ in 0..n {
        qwq.push(cin!([i32; m + 1]));
    }
    let dfs = || {
        let mut st = Vec::new();
        st.push((0, vec![0; m], 0));
        let mut ans = i32::MAX;
        while let Some((cost, skill, i)) = st.pop() {
            if i == n {
                if skill.iter().all(|t| *t >= x as i32) {
                    ans = ans.min(cost)
                }
                continue;
            } else if !skill.iter().all(|t| *t >= x as i32) {
                let ns = skill
                    .iter()
                    .enumerate()
                    .map(|(j, p)| qwq[i][j + 1] + *p)
                    .collect::<Vec<_>>();
                st.push((cost + qwq[i][0], ns, i + 1))
            }
            st.push((cost, skill, i + 1))
        }
        if ans == i32::MAX {
            -1
        } else {
            ans
        }
    };
    println!("{}", dfs());
}
