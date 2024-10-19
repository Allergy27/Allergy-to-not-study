//@author    Allergy
//@workspace study/bm.rs
//@data      2024/10/10 19:15:05
use {rand::Rng, std::collections::HashMap};
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
    let (a, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let trans = |x: char| match x {
        'A' => 'T',
        'T' => 'A',
        'C' => 'G',
        'G' => 'C',
        _ => ' ',
    };
    let show = |qwq: &Vec<char>| {
        qwq.iter().for_each(|x| print!("{}", x));
        println!()
    };
    let dna_init = random_dna(a);
    let dna = dna_init.iter().map(|x| trans(*x)).collect::<Vec<char>>();
    let pattern = random_dna(b);

    show(&dna_init);
    println!("↓");
    show(&pattern);
    boyer_moore(dna, &pattern);
}
fn random_dna(length: usize) -> Vec<char> {
    let nucleotides = ['A', 'T', 'C', 'G']; // DNA碱基
    let mut rng = rand::thread_rng(); // 创建随机数生成器

    // 随机生成指定长度的DNA序列
    let sequence: String = (0..length)
        .map(|_| nucleotides[rng.gen_range(0..4)]) // 随机选择ATCG中的一个
        .collect();

    sequence.chars().collect()
}

fn boyer_moore(text: Vec<char>, pattern: &Vec<char>) {
    // 坏字符规则：生成坏字符表
    let bad_str = |pattern: &Vec<char>, qwq: &mut HashMap<char, i32>| {
        for (i, &ch) in pattern.iter().enumerate() {
            qwq.insert(ch, i as i32);
        }
    };
    // 好后缀规则
    let _good_suffix = |pattern: &Vec<char>, qwq: &mut Vec<i32>| {
        let m = pattern.len();
        let mut f = vec![0; m + 1];
        let mut i = m;
        let mut j = m + 1;
        while i > 0 {
            while j <= m && pattern[i - 1] != pattern[j - 1] {
                if qwq[j] as usize == m {
                    //滑动距离
                    qwq[j] = j as i32 - i as i32;
                }
                j = f[j];
            }
            i -= 1;
            j -= 1;
            f[i] = j;
        }
        for (i, qwq_val) in qwq.iter_mut().enumerate() {
            if *qwq_val == m as i32 {
                *qwq_val = m as i32 - i as i32;
            }
        }
    };
    let n = text.len();
    let m = pattern.len();
    if m == 0 {
        println!("模式串为空，返回0");
        return;
    }
    // 坏字符表（ASCII字符集大小256）
    let mut bad_char = HashMap::new();
    // let mut good_suf = vec![-1; m + 1];
    bad_str(pattern, &mut bad_char);
    // good_suffix(&pattern, &mut good_suf);
    // 开始匹配
    let mut i = 0;
    while i <= n - m {
        let mut j = m - 1;
        let mut check = false;
        //从末位开始判断
        while pattern[j] == text[i + j] {
            if j == 0 {
                check = true;
                break;
            }
            j -= 1;
        }

        if check {
            println!("成功匹配，索引位于{}", i + 1);
            i += if i + m < n {
                (m as i32 - *bad_char.get(&text[i + m]).unwrap_or(&-1)) as usize
            } else {
                1
            };
        } else {
            i += 1
                .max(j as i32 - { *bad_char.get(&text[i + j]).unwrap_or(&-1) })
                // .max(good_suf[j + 1])
                 as usize;
        }
    }
}
