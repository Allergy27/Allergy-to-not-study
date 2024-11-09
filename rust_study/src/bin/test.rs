use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};

// 构建哈夫曼树，返回邻接表、根节点索引和字符表
fn build_huffman_tree(
    frequencies: HashMap<char, usize>,
) -> (Vec<Vec<i32>>, usize, Vec<Option<char>>) {
    let mut heap = BinaryHeap::new();
    let mut adj_list: Vec<Vec<i32>> = Vec::new(); // 邻接表
    let mut char_map: Vec<Option<char>> = Vec::new(); // 每个节点的字符（仅叶节点）

    // 初始化叶节点并加入优先队列
    for (ch, freq) in frequencies {
        let index = adj_list.len();
        adj_list.push(Vec::new()); // 为每个节点初始化空的邻接列表
        char_map.push(Some(ch));
        heap.push(Reverse((freq, Some(ch), index))); // 使用 Reverse 使得最小频率优先
    }

    // 构建哈夫曼树
    while heap.len() > 1 {
        let Reverse((freq_left, _, left_index)) = heap.pop().unwrap();
        let Reverse((freq_right, _, right_index)) = heap.pop().unwrap();
        let new_freq = freq_left + freq_right;

        // 创建新的内部节点并加入邻接表
        let index = adj_list.len();
        adj_list.push(vec![left_index as i32, right_index as i32]);
        char_map.push(None); // 内部节点没有字符

        // 将新节点加入优先队列
        heap.push(Reverse((new_freq, None, index)));
    }

    // 剩下的最后一个节点是根节点
    let root_index = heap.pop().unwrap().0 .2;
    (adj_list, root_index, char_map)
}

// 生成哈夫曼编码
fn generate_codes(
    adj_list: &Vec<Vec<i32>>,
    char_map: &Vec<Option<char>>,
    index: usize,
    code: String,
    codes: &mut HashMap<char, String>,
) {
    if let Some(character) = char_map[index] {
        codes.insert(character, code);
    } else {
        if let Some(&left) = adj_list[index].first() {
            generate_codes(
                adj_list,
                char_map,
                left as usize,
                format!("{}0", code),
                codes,
            );
        }
        if let Some(&right) = adj_list[index].get(1) {
            generate_codes(
                adj_list,
                char_map,
                right as usize,
                format!("{}1", code),
                codes,
            );
        }
    }
}

// 主函数：从字符串生成哈夫曼编码
fn huffman_encoding(input: &str) -> HashMap<char, String> {
    let mut frequencies = HashMap::new();
    for ch in input.chars() {
        *frequencies.entry(ch).or_insert(0) += 1;
    }

    let (adj_list, root_index, char_map) = build_huffman_tree(frequencies);
    let mut codes = HashMap::new();
    generate_codes(&adj_list, &char_map, root_index, String::new(), &mut codes);

    codes
}

fn main() {
    let input = "hello huffman";
    let codes = huffman_encoding(input);

    println!("Character Huffman Codes:");
    for (ch, code) in codes {
        println!("'{}': {}", ch, code);
    }
}
