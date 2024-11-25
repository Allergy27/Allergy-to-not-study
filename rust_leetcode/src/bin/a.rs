use std::i32;

//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/a.rs
//@data      2024/11/24 10:30:16
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
fn solve() {}

struct Solution;

impl Solution {
    //C
    pub fn min_array_sum(mut nums: Vec<i32>, k: i32, op1: i32, op2: i32) -> i32 {
        let n = nums.len();
        let mut dp = vec![vec![vec![i32::MAX; (op2 + 1) as usize]; (op1 + 1) as usize]; n + 1];

        dp[0][0][0] = nums.iter().sum();

        for i in 0..n {
            for x in 0..=op1 {
                for y in 0..=op2 {
                    let cur = nums[i];
                    dp[i + 1][x as usize][y as usize] =
                        dp[i + 1][x as usize][y as usize].min(dp[i][x as usize][y as usize]);
                    if x < op1 {
                        let tmp = (cur + 1) / 2;
                        dp[i + 1][(x + 1) as usize][y as usize] = dp[i + 1][(x + 1) as usize]
                            [y as usize]
                            .min(dp[i][x as usize][y as usize] - cur + tmp);
                    }
                    if y < op2 && cur >= k {
                        let tmp = cur - k;
                        dp[i + 1][x as usize][(y + 1) as usize] = dp[i + 1][x as usize]
                            [(y + 1) as usize]
                            .min(dp[i][x as usize][y as usize] - cur + tmp);
                    }
                }
            }
        }
        let mut ans = i32::MAX;
        for x in 0..=op1 {
            for y in 0..=op2 {
                ans = ans.min(dp[n][x as usize][y as usize]);
            }
        }
        ans
    }
}

// impl Solution {
//     //C
//     pub fn min_array_sum(mut nums: Vec<i32>, k: i32, op1: i32, op2: i32) -> i32 {
//         nums.sort_unstable();
//         let mut qwq = nums.clone();
//         let n = qwq.len();
//         let mut is_op1 = vec![false; n];
//         let mut op2 = op2;
//         let mut start = Vec::new();
//         let mut pos = 0;
//         for i in 0..n {
//             if op2 > 0 && qwq[i] >= k && (qwq[i] - (qwq[i] + 1) / 2) <= k {
//                 qwq[i] -= k;
//                 op2 -= 1;
//                 start.push(i);
//             } else if (qwq[i] - (qwq[i] + 1) / 2) > k {
//                 if op2 == 0 && pos < start.len() {
//                     qwq[start[pos]] += k;
//                     pos += 1;
//                     start.push(i);
//                 }
//                 qwq[i] = (qwq[i] + 1) / 2;
//                 qwq[i] -= k;
//                 is_op1[i] = true;
//             }
//         }
//         let mut op1 = op1;
//         let mut tmp = (0..n).collect::<Vec<_>>();
//         tmp.sort_unstable_by(|x, y| qwq[*y].cmp(&qwq[*x]));
//         for i in 0..n {
//             if op1 == 0 {
//                 break;
//             }
//             if is_op1[tmp[i]] {
//                 continue;
//             }
//             op1 -= 1;
//             qwq[tmp[i]] = (qwq[tmp[i]] + 1) / 2
//         }
//         qwq.into_iter().sum::<i32>()
//     }
// }
// impl Solution {
//     //C
//     pub fn min_array_sum(mut nums: Vec<i32>, k: i32, op1: i32, op2: i32) -> i32 {
//         let op1 = op1 as usize;
//         let n = nums.len();
//         nums.sort_unstable_by(|x, y| y.cmp(x));
//         let mut qwq = nums.clone();
//         qwq.iter_mut().take(op1).for_each(|x| *x = (*x + 1) / 2);
//         let mut op2 = op2;

//         let mut get_op2 = vec![false; n];
//         for i in (0..n).rev() {
//             if op2 == 0 {
//                 break;
//             }
//             if qwq[i] >= k {
//                 get_op2[i] = true;
//                 qwq[i] -= k;
//                 op2 -= 1;
//             }
//         }
//         let mut tmp = op1;
//         for i in (0..op1).rev() {
//             if op2 == 0 {
//                 break;
//             }
//             while tmp < n && get_op2[tmp] {
//                 tmp += 1;
//             }
//             if nums[i] >= k && k > (nums[i] - qwq[i]) {
//                 qwq[i] = nums[i] - k;
//                 if tmp < n && qwq[tmp] > qwq[i] {
//                     qwq[tmp] = (qwq[tmp] + 1) / 2;
//                     tmp += 1;
//                 } else {
//                     qwq[i] = (qwq[i] + 1) / 2;
//                 }
//                 op2 -= 1;
//             }
//         }
//         qwq.iter().sum::<i32>()
//     }
// }

// impl Solution {
//     // B
//     pub fn is_possible_to_rearrange(s: String, t: String, k: i32) -> bool {
//         let k = k as usize;
//         let n = s.len();
//         if n % k != 0 {
//             return false;
//         }
//         let s = s.as_bytes();
//         let t = t.as_bytes();
//         let mut qwq = std::collections::BTreeMap::new();
//         let mut qaq = std::collections::BTreeMap::new();
//         let mut tmp1 = Vec::with_capacity(k);
//         let mut tmp2 = Vec::with_capacity(k);
//         let p = n / k;
//         for i in (0..n).step_by(p) {
//             // println!("{i}");
//             for j in i..i + p {
//                 tmp1.push(s[j]);
//                 tmp2.push(t[j]);
//             }
//             *qwq.entry(tmp1.clone()).or_insert(0) += 1;
//             *qaq.entry(tmp2.clone()).or_insert(0) += 1;
//             tmp1.clear();
//             tmp2.clear();
//             println!("{i} {:?}", qwq);
//             println!("{i} {:?}", qaq);
//         }
//         for ((a, b), (c, d)) in qwq.iter().zip(qaq) {
//             if *a != c || *b != d {
//                 return false;
//             }
//         }
//         true
//     }
// }
// impl Solution { // A
//     pub fn minimum_sum_subarray(nums: Vec<i32>, l: i32, r: i32) -> i32 {
//         let n = nums.len();
//         let mut ans = i32::MAX;
//         for i in l..r {
//             let mut tmp = (0..i).fold(0, |ans, x| ans + nums[x as usize]);
//             if tmp > 0 {
//                 ans = ans.min(tmp);
//             }
//             for j in i as usize..n {
//                 tmp -= nums[j - i as usize];
//                 tmp += nums[j];
//                 if tmp > 0 {
//                     ans = ans.min(tmp)
//                 }
//             }
//         }
//         if ans != i32::MAX {
//             ans
//         } else {
//             -1
//         }
//     }
// }
