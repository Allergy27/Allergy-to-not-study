
use std::collections::{BTreeSet, VecDeque};
use std::io::{self, BufRead, Write};

fn solve() {
    let stdin = io::stdin();
    let mut stdin = stdin.lock().lines();
    let mut stdout = io::stdout();
    let mut stdout = stdout.lock();

    let ti: i64 = stdin.next().unwrap().unwrap().trim().parse().unwrap();
    for _ in 0..ti {
        let n: usize = stdin.next().unwrap().unwrap().trim().parse().unwrap();
        let mut w: Vec<i64> = vec![0; n + 1];
        let mut pq = BTreeSet::new();
        let mut ans = Vec::new();
        let mut st = VecDeque::new();
        let mut h = Vec::new();

        for i in 1..=n {
            w[i] = stdin.next().unwrap().unwrap().trim().parse().unwrap();
            st.push_back(w[i]);
            pq.insert(w[i]);
        }

        while !st.is_empty() {
            let x = st.pop_front().unwrap();
            pq.remove(&x);
            if st.is_empty() {
                h.sort();
                for &x in &h {
                    st.push_back(x);
                }
                h.clear();
            }
            if st.is_empty() {
                ans.push(x);
            } else {
                if *pq.iter().next().unwrap() < x {
                    pq.insert(x + 1);
                    h.push(x + 1);
                } else {
                    ans.push(x);
                }
            }
        }

        for x in ans {
            write!(stdout, "{} ", x).unwrap();
        }
        writeln!(stdout).unwrap();
    }
}