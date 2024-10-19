//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\2208.rs
//@data      2023/12/06 20:52:49
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    for _ in 0..t {
        solve()
    }
}
fn solve() {
    fn halve_array(nums: Vec<i32>) -> i32 {
        let t = nums.len() - 1;
        if t == 0 {
            return 1;
        }
        let s: f64 = nums.iter().map(|&x| x as f64).sum();
        let s = s / 2.0;
        let mut nums = nums.iter().map(|&x| x as f64).collect::<Vec<f64>>();
        let mut qwq = 0.0;
        let mut time = 0;
        while s > qwq {
            nums.sort_unstable_by(|a, b| a.partial_cmp(b).unwrap());
            let k = nums[t] / 2.0;
            let mut p = 0;
            let mut q = t;
            let mut m = 0;
            while p < q {
                m = (p + q) / 2;
                if nums[m] < k && nums[m + 1] > k {
                    break;
                } else if nums[m] < k {
                    p = m
                } else {
                    q = m + 1;
                }
            }
            for i in (m + 1..=t).rev() {
                time += 1;
                nums[i] /= 2.0;
                qwq += nums[i];
                if qwq >= s {
                    return time;
                }
            }
        }
        time
    }
    let nums = vec![6, 58, 10, 84, 35, 8, 22, 64, 1, 78, 86, 71, 77];
    println!("{}", halve_array(nums));
}
