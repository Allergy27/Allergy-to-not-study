//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\2454.rs
//@data      2023/12/12 17:46:18
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    for _ in 0..t {
        solve()
    }
}
fn solve() {
    let qwq = vec![2, 4, 0, 9, 6];
    let qwq = second_greater_element(qwq);
    for i in qwq.iter() {
        println!("{}", i)
    }
}

fn second_greater_element(nums: Vec<i32>) -> Vec<i32> {
    let mut ans = vec![-1; nums.len()]; //初始化成-1
    let mut one = Vec::new(); //下一个更大的
    let mut two = Vec::new(); //下两个更大的
    for (i, &k) in nums.iter().enumerate() {
        while !two.is_empty() && nums[*two.last().unwrap()] < k {
            ans[two.pop().unwrap()] = k;
        }
        let j = if let Some(x) = (0..one.len()).rev().find(|x| nums[one[*x]] >= k) {
            x + 1
        } else {
            0
        };
        two.extend(one.drain(j..));
        one.push(i)
    }
    ans
}
