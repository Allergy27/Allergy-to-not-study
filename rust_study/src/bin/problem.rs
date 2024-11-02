//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/problem.rs
//@data      2024/11/01 07:25:05

use rand::Rng;
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| check());
}
fn solve(n: usize, que: std::collections::VecDeque<usize>) -> u32 {
    let mut que = que.clone();
    let mut small = Vec::new();
    let mut big = Vec::new();
    for i in 0..n {
        if que.back().unwrap() > que.front().unwrap() {
            small.push(que.pop_back().unwrap());
        } else {
            big.push(que.pop_front().unwrap());
        }
    }
    1
}

fn check() {
    for _ in 0..20 {
        let mut rng = rand::thread_rng();
        let mut arr = vec![0; 9];
        for x in &mut arr {
            *x = rng.gen_range(0..=100);
        }
        let que = std::collections::VecDeque::from_iter(arr);
        let n = que.len();
        let dfs = || -> u32 {
            let mut st = vec![];
            st.push((1, 0));
            st.push((1, 1));
            let mut ans = 0;
            while let Some((idx, l)) = st.pop() {
                if idx >= n {
                    let mut k = l;
                    let mut tmp = 0;
                    let mut cul = que.clone();
                    for i in 1..=n {
                        if (k & 1) == 1 {
                            tmp += cul.pop_front().unwrap() * i;
                        } else {
                            tmp += cul.pop_back().unwrap() * i;
                        }
                        k >>= 1;
                    }
                    ans = ans.max(tmp);
                } else {
                    st.push((idx + 1, l << 1));
                    st.push((idx + 1, l << 1 | 1));
                }
            }
            ans as _
        };
        let k1 = solve(n, que.clone());
        let k2 = dfs();
        if k1 != k2 {
            println!("error");
            println!("{:?}", que);
            println!("{:?}", k1);
            println!("{:?}", k2);
        }
    }
}
