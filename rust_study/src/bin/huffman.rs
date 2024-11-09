//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/hafuman.rs
//@data      2024/11/09 12:00:55
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
    use std::cmp::Reverse;
    //原字符串
    // let s = cin!();
    let s = "
敌人越是反对我，越说明我做对了。
连敌人都不得不支持我，更说明我做对了。
朋友越是支持我，越说明我做对了。
如果朋友反对我，说明他也是敌人。
路人越是支持我，越说明我做对了。
路人反对我，说明路人是敌人。
敌人，朋友，路人都支持我，更说明我走在一条正确的道路上。";

    //统计词频
    let mut qwq = std::collections::HashMap::<char, i32>::new();
    for c in s.chars() {
        *qwq.entry(c).or_insert(0) += 1
    }
    let build = || {
        //建树
        let n = qwq.len();
        let mut huffman_tree = Vec::with_capacity(n);
        let mut char_map = Vec::with_capacity(n);
        let mut que = std::collections::BinaryHeap::new();
        for (i, (&c, &w)) in qwq.iter().enumerate() {
            huffman_tree.push(Vec::new());
            char_map.push(Some(c)); //每个节点一开始都认为是叶子
            que.push(Reverse((w, Some(c), i)));
        }
        while que.len() > 1 {
            let Reverse((wl, _, il)) = que.pop().unwrap();
            let Reverse((wr, _, ir)) = que.pop().unwrap();
            let nw = wl + wr;
            huffman_tree.push(vec![il as i32, ir as i32]);
            char_map.push(None); //内部节点没有字符
            que.push(Reverse((nw, None, huffman_tree.len() - 1)))
        }
        let root = que.pop().unwrap().0 .2;
        (root, huffman_tree, char_map)
    };
    let (root, huffman_tree, char_map) = build();
    let coding = || {
        //由哈夫曼树构造哈夫曼编码
        let mut codes = std::collections::HashMap::new();
        let mut stk = Vec::new();
        stk.push((root, String::new()));
        while let Some((i, code)) = stk.pop() {
            if let Some(c) = char_map[i] {
                codes.insert(c, code);
            } else {
                // 如果是内部节点，将左右子节点加入栈
                if let Some(&left) = huffman_tree[i].first() {
                    stk.push((left as usize, format!("{}0", code))); // 左子节点编码加 "0"
                }
                if let Some(&right) = huffman_tree[i].get(1) {
                    stk.push((right as usize, format!("{}1", code))); // 右子节点编码加 "1"
                }
            }
        }
        codes
    };
    let huffman_codes = coding();
    // 计算原始编码和哈夫曼编码的码长
    let savings = || {
        // 原始编码的总码长
        let ori_len: usize = s.chars().map(|c| if c.is_ascii() { 8 } else { 32 }).sum();
        let huff_len: usize = qwq
            .iter()
            .map(|(ch, &time)| huffman_codes.get(ch).unwrap().len() * time as usize)
            .sum();
        // 输出结果
        println!("源文本占用:{} bits", ori_len);
        println!("编码后占用: {} bits", huff_len);
        println!("共节省bit: {} bits", ori_len - huff_len);
        println!(
            "压缩率: {:.2}%",
            100.0 * (ori_len - huff_len) as f64 / ori_len as f64
        );
    };

    let decode = |encoded: &str| {
        let mut ans = String::new();
        let mut cur = root;
        for bit in encoded.chars() {
            // 根据bit移动到左或右子节点
            if bit == '0' {
                cur = huffman_tree[cur][0] as usize;
            } else {
                cur = huffman_tree[cur][1] as usize;
            }
            // 检查是否到达叶节点
            if let Some(ch) = char_map[cur] {
                ans.push(ch);
                cur = root; //回到根
            }
        }
        ans
    };
    //p代表编码后字符串
    let p: String = s
        .chars()
        .map(|x| huffman_codes.get(&x).unwrap().as_str())
        .collect();
    qwq.iter().for_each(|x| println!("{:?}", x));
    huffman_codes.iter().for_each(|x| println!("{:?} ", x));
    println!("{:?}\n{:?}", p, decode(&p));
    savings();
}
