//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace atcoder/cute_dog.rs
//@data      2024/10/12 18:28:58
use proconio::input;
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}

fn solve() {
    input! {
        n: usize,
        d: [(i64, char); 2 * n],
    }

    let mut qwq = vec![vec![]; 3];
    for (a, c) in d {
        match c {
            'R' => qwq[0].push(a),
            'G' => qwq[1].push(a),
            'B' => qwq[2].push(a),
            _ => unreachable!(),
        }
    }

    for x in qwq.iter_mut() {
        x.sort_unstable()
    }
    let check = |a: &Vec<i64>, b: &Vec<i64>| -> i64 {
        let (mut i, mut j) = (0, 0);
        let (a_len, b_len) = (a.len(), b.len());
        let mut ans = i64::MAX;
        while i < a_len && j < b_len {
            ans = ans.min(a[i].abs_diff(b[j]) as i64);
            if a[i] < b[j] {
                i += 1;
            } else {
                j += 1;
            }
        }
        ans
    };
    let ans = if qwq[0].len() % 2 == 0 && qwq[1].len() % 2 == 0 {
        0
    } else {
        if qwq[0].len() % 2 == 0 {
            qwq.swap(0, 2);
        } else if qwq[1].len() % 2 == 0 {
            qwq.swap(1, 2);
        }
        let ab = check(&qwq[0], &qwq[1]);
        if !qwq[2].is_empty() {
            let ac = check(&qwq[0], &qwq[2]);
            let bc = check(&qwq[1], &qwq[2]);
            ab.min(ac + bc)
        } else {
            ab
        }
    };
    println!("{}", ans);
}
