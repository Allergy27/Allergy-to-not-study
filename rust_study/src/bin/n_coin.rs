//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/n_coin.rs
//@data      2024/11/09 08:59:09
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

fn solve() {
    let n = cin!(usize);
    let coin = (0..n).collect();
    let mut weight = vec![1; n];
    //假设假币要轻
    weight[rand::random::<usize>() % n] = 0;
    //分堆
    let split = |coins: &Vec<usize>| {
        let n = coins.len();
        let res = n % 3;
        let a = coins[0..n / 3].to_vec();
        let b = coins[n / 3..n / 3 * 2].to_vec();
        let c = coins[n / 3 * 2..(n - res)].to_vec();
        let r = coins[n - res..n].to_vec();
        (a, b, c, r)
    };
    //模拟天平上称
    let check = |a: &Vec<usize>, b: &Vec<usize>| {
        a.iter()
            .map(|x| weight[*x])
            .sum::<usize>()
            .cmp(&b.iter().map(|y| weight[*y]).sum::<usize>())
    };
    //判断哪个是假币
    let judge = |con: &Vec<usize>, time: usize| match con.len() {
        1 => (con[0], time),
        2 => (
            if weight[con[0]] > weight[con[1]] {
                con[1]
            } else {
                con[0]
            },
            time + 1,
        ),
        3 => (
            match weight[con[0]].cmp(&weight[con[1]]) {
                std::cmp::Ordering::Equal => con[2],
                std::cmp::Ordering::Greater => con[1],
                std::cmp::Ordering::Less => con[0],
            },
            time + 1,
        ),
        _ => unreachable!(),
    };
    /*
        //输出分堆情况
        let show = |tmp: &Vec<usize>| {
            if let Some(h) = tmp.first() {
                format!("[ {} 到 {} ]", h, tmp.last().unwrap())
            } else {
                String::from("Empty")
            }
        };
    */
    let find = |coins: &Vec<usize>| {
        let mut que = std::collections::VecDeque::new();
        if coins.len() <= 3 {
            return judge(coins, 1);
        }
        que.push_back((split(coins), 1));
        while let Some(((a, b, c, r), time)) = que.pop_front() {
            /*
            println!(
                "分为:\na:{}\nb:{}\nc:{}\nr:{}\n",
                show(&a),
                show(&b),
                show(&c),
                show(&r)
            );
            */
            match check(&a, &b) {
                //a=b，假币在c/r
                std::cmp::Ordering::Equal => {
                    // println!("第{}次:比较a b堆天平平衡", time);
                    if c.is_empty() || check(&a, &c) == std::cmp::Ordering::Equal {
                        // println!("第{}次:比较a c堆天平平衡,故比较剩余堆 r ", time + 1);
                        return judge(&r, time + 1);
                    } else if c.len() <= 3 {
                        // println!("第{}次:比较 c 堆", time + 1);
                        return judge(&c, time + 1);
                    } else {
                        // print!("将 c ");
                        que.push_back((split(&c), time + 1));
                    }
                }
                //a>b，在b
                std::cmp::Ordering::Greater => {
                    // println!("第{}次:比较a b堆 a 更重", time);
                    if b.len() <= 3 {
                        // if b.len() != 1 {
                        //     println!("第{}次:比较 b 堆", time + 1);
                        // }
                        return judge(&b, time);
                    } else {
                        // print!("将 b ");
                        que.push_back((split(&b), time + 1));
                    }
                }
                //a<b，在a
                std::cmp::Ordering::Less => {
                    // println!("第{}次:比较a b堆 b 更重", time);
                    if a.len() <= 3 {
                        // if a.len() != 1 {
                        //     println!("第{}次:比较 a 堆", time + 1);
                        // }
                        return judge(&a, time);
                    } else {
                        // print!("将 a ");
                        que.push_back((split(&a), time + 1));
                    }
                }
            }
        }
        unreachable!()
    };
    println!("{:?}", find(&coin));
    println!(
        "{:?}", //输出正确答案
        (0..n).filter(|&x| weight[x] == 0).collect::<Vec<_>>()
    );
}
