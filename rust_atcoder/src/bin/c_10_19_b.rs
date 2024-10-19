//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace rust_atcoder/c_10_19_b.rs
//@data      2024/10/19 20:08:16
use proconio::input;

fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        n:usize,
        m:usize,
        op:[(char,usize);m],
    }
    let mut l_hand = 1;
    let mut r_hand = 2;
    let find = |a: usize, b: usize| {
        if a < b {
            a + n - b
        } else {
            a - b
        }
    };

    let mut check = |hand: char, pos: usize| {
        let (start_pos, another_pos) = match hand {
            'R' => {
                let tmp = r_hand;
                r_hand = pos;
                (tmp, l_hand)
            }
            'L' => {
                let tmp = l_hand;
                l_hand = pos;
                (tmp, r_hand)
            }
            _ => unreachable!(),
        };
        let r_find = if find(start_pos, pos) < find(another_pos, pos) {
            find(start_pos, pos)
        } else {
            usize::MAX
        };
        let l_find = if find(pos, start_pos) < find(pos, another_pos) {
            find(pos, start_pos)
        } else {
            usize::MAX
        };
        r_find.min(l_find)
    };
    let mut ans = 0;
    for (hd, ps) in op {
        ans += check(hd, ps);
    }
    println!("{}", ans);
}
