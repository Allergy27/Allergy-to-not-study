use std::collections::HashMap;

/// 快速幂计算 (x^y % MOD)
fn fast_pow(mut x: u64, mut y: u64, modulo: u64) -> u64 {
    let mut result = 1;
    while y > 0 {
        if y % 2 == 1 {
            result = result * x % modulo;
        }
        x = x * x % modulo;
        y /= 2;
    }
    result
}

fn count_gcd_1_subsets(array: Vec<usize>) -> u64 {
    let max_val = 1_000_000; // 数值上限
    let modulo = 1_000_000_007; // 取模
    let mut cnt = vec![0; max_val + 1];

    // 统计每个数的出现次数
    for &num in &array {
        cnt[num] += 1;
    }

    // 计算每个数的倍数出现的频率
    let mut multiple_count = vec![0; max_val + 1];
    for x in 1..=max_val {
        let mut y = x;
        while y <= max_val {
            multiple_count[x] += cnt[y];
            y += x;
        }
    }

    // 计算以 x 为 GCD 的子集数量 g[x]
    let mut g = vec![0u64; max_val + 1];
    for x in (1..=max_val).rev() {
        if multiple_count[x] > 0 {
            // f[x] = 2^(cnt[x]) - 1
            let f_x = (fast_pow(2, multiple_count[x] as u64, modulo) + modulo - 1) % modulo;
            g[x] = f_x;

            // 容斥，减去 g[2x], g[3x], ...
            let mut y = 2 * x;
            while y <= max_val {
                g[x] = (g[x] + modulo - g[y]) % modulo;
                y += x;
            }
        }
    }

    // 返回 g[1]，即 GCD 为 1 的子集数量
    g[1]
}

fn main() {
    let array = vec![2, 3, 4, 6]; // 示例输入
    let result = count_gcd_1_subsets(array);
    println!("Number of subsets with GCD = 1: {}", result);
}
