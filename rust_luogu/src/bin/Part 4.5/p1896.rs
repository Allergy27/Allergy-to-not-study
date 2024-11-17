//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1896.rs
//@data      2024/10/16 19:19:25
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}

fn solve() {
    let (n, k) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut len = vec![]; //存储状态下用了几个1
    let mut sit = vec![]; //存储状态

    let mut dfs = || {
        //预处理所有状态
        let mut stack = vec![];
        stack.push((0i64, 0, 0));
        while !stack.is_empty() {
            // println!("{:?}",stack);
            if let Some(x) = stack.pop() {
                if x.2 >= n {
                    sit.push(x.0);
                    len.push(x.1);
                    continue;
                }
                stack.push((x.0, x.1, x.2 + 1)); //当前位置不放
                stack.push((x.0 + (1 << x.2), x.1 + 1, x.2 + 2)); //当前位置放
            };
        }
    };
    dfs();
    let cnt = sit.len();
    let mut dp = vec![vec![vec![0; n * n]; cnt]; n];
    //i: 第i行 j:这一行状态 k:用了几个
    //dp[i][j][k] 方案数
    for (i, &x) in len.iter().enumerate() {
        dp[0][i][x] = 1
    }
    for i in 1..n {
        //当前行
        for j in 0..cnt {
            //上一行
            for t in 0..cnt {
                if sit[j] & sit[t] == 0
                    && (sit[j] << 1) & sit[t] == 0
                    && sit[j] & (sit[t] << 1) == 0
                {
                    for res in (len[j]..=k).rev() {
                        dp[i][j][res] += dp[i - 1][t][res - len[j]];
                    }
                }
            }
        }
    }
    // println!("{:?}",dp[n-1]);
    let res = (0..cnt).fold(0i64, |ans, i| ans + dp[n - 1][i][k]);
    println!("{}", res);
}
