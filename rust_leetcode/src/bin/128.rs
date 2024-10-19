use std::cmp::Ordering;
use std::collections::BinaryHeap;

//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/128.rs
//@data      2023/12/24 19:10:26

fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| {
        println!("{}", solve(vec![0, 1, 1, 2]));
    });
}

pub fn solve(nums: Vec<i32>) -> i32 {
    if nums.is_empty() {
        return 0;
    }
    let mut nums = BinaryHeap::from(nums);
    let (mut ans, mut now) = (1, 1);
    let mut qaq = nums.pop().unwrap();
    while !nums.is_empty() {
        let qwq = nums.pop().unwrap();
        match qwq.cmp(&(qaq - 1)) {
            Ordering::Equal => now += 1,
            Ordering::Less => now = 1,
            Ordering::Greater => {}
        }
        qaq = qwq;
        ans = ans.max(now);
    }
    ans
}
