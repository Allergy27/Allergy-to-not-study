//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/2276.rs
//@data      2023/12/16 19:07:19
use std::cmp::Ordering::*;
use std::collections::BTreeMap;
struct _CountIntervals {
    m: BTreeMap<i32, i32>, // （right, left）
    cnt: i32,
}

impl _CountIntervals {
    fn _new() -> Self {
        Self {
            m: BTreeMap::new(),
            cnt: 0,
        }
    }

    fn _add(&mut self, mut left: i32, mut right: i32) {
        let mut need_sub = 0;
        let need_del = self
            .m
            .range(left - 1..)
            .map_while(|(r, l)| match right.cmp(l) {
                Greater | Equal => {
                    left = left.min(*l);
                    right = right.max(*r);
                    need_sub += *r - *l + 1;
                    Some(*r)
                }
                Less => None,
            })
            .collect::<Vec<_>>();
        for r in &need_del {
            self.m.remove(r);
        }
        self.cnt += right - left + 1 - need_sub;
        self.m.insert(right, left);
    }
    fn _count(&self) -> i32 {
        self.cnt
    }
}

fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
}
