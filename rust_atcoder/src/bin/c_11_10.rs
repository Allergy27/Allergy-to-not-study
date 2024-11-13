//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/c_11_10.rs
//@data      2024/11/10 14:26:04
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
    let mut mackerels = Vec::new();
    let mut sardines = Vec::new();
    for i in 0..2 * n {
        let coords = cin!([i64; 2]);
        if i < n {
            mackerels.push((coords[0], coords[1]));
        } else {
            sardines.push((coords[0], coords[1]));
        }
    }

    let count_fish = |x1: i64, y1: i64, x2: i64, y2: i64| -> (i32, i32) {
        let mut a = 0;
        let mut b = 0;
        for &(x, y) in &mackerels {
            if (x1..=x2).contains(&x) && (y1..=y2).contains(&y) {
                a += 1;
            }
        }
        for &(x, y) in &sardines {
            if (x1..=x2).contains(&x) && (y1..=y2).contains(&y) {
                b += 1;
            }
        }
        (a, b)
    };
    let mut best_score = i32::MIN;
    let mut best_coords = (0, 0, 0, 0);
    let mut best_rects = vec![(0, 0, 100000, 100000)]; // 初始矩形区域
                                                       // 二分查找 x 方向
    let mut left = 0;
    let mut right = 100000;
    while left < right {
        let mid = (left + right) / 2;
        let (a1, b1) = count_fish(0, 0, mid, 100000);
        let (a2, b2) = count_fish(mid + 1, 0, 100000, 100000);
        let score1 = a1 - b1;
        let score2 = a2 - b2;
        if score1 > score2 {
            right = mid;
            if score1 > best_score {
                best_score = score1;
                best_coords = (0, 0, mid, 100000);
            }
        } else {
            left = mid + 1;
            if score2 > best_score {
                best_score = score2;
                best_coords = (mid + 1, 0, 100000, 100000);
            }
        }
    }

    // 二分查找 y 方向
    left = 0;
    right = 100000;
    while left < right {
        let mid = (left + right) / 2;
        let (a1, b1) = count_fish(best_coords.0, best_coords.1, best_coords.2, mid);
        let (a2, b2) = count_fish(best_coords.0, mid + 1, best_coords.2, 100000);
        let score1 = a1 - b1;
        let score2 = a2 - b2;
        if score1 > score2 {
            right = mid;
            if score1 > best_score {
                best_score = score1;
                best_coords = (best_coords.0, best_coords.1, best_coords.2, mid);
            }
        } else {
            left = mid + 1;
            if score2 > best_score {
                best_score = score2;
                best_coords = (best_coords.0, mid + 1, best_coords.2, 100000);
            }
        }
    }

    // 在四个方向上扩展区域，合并相邻矩形
    let mut expanded = true;
    while expanded {
        expanded = false;
        let (min_x, min_y, max_x, max_y) = best_coords;

        // 尝试合并左侧相邻的矩形
        if min_x > 0 {
            let (left_x1, left_y1, left_x2, left_y2) = (0, min_y, min_x - 1, max_y);
            let total_a = count_fish(left_x1, left_y1, max_x, max_y).0;
            let total_b = count_fish(left_x1, left_y1, max_x, max_y).1;
            let score = total_a - total_b;
            if score > best_score {
                best_score = score;
                best_coords = (left_x1, min_y, max_x, max_y);
                best_rects.push((left_x1, left_y1, left_x2, left_y2));
                expanded = true;
                continue;
            }
        }

        // 尝试合并右侧相邻的矩形
        if max_x < 100000 {
            let (right_x1, right_y1, right_x2, right_y2) = (max_x + 1, min_y, 100000, max_y);
            let total_a = count_fish(min_x, min_y, right_x2, max_y).0;
            let total_b = count_fish(min_x, min_y, right_x2, max_y).1;
            let score = total_a - total_b;
            if score > best_score {
                best_score = score;
                best_coords = (min_x, min_y, right_x2, max_y);
                best_rects.push((right_x1, right_y1, right_x2, right_y2));
                expanded = true;
                continue;
            }
        }

        // 尝试合并下方相邻的矩形
        if min_y > 0 {
            let (bottom_x1, bottom_y1, bottom_x2, bottom_y2) = (min_x, 0, max_x, min_y - 1);
            let total_a = count_fish(min_x, bottom_y1, max_x, max_y).0;
            let total_b = count_fish(min_x, bottom_y1, max_x, max_y).1;
            let score = total_a - total_b;
            if score > best_score {
                best_score = score;
                best_coords = (min_x, bottom_y1, max_x, max_y);
                best_rects.push((bottom_x1, bottom_y1, bottom_x2, bottom_y2));
                expanded = true;
                continue;
            }
        }

        // 尝试合并上方相邻的矩形
        if max_y < 100000 {
            let (top_x1, top_y1, top_x2, top_y2) = (min_x, max_y + 1, max_x, 100000);
            let total_a = count_fish(min_x, min_y, max_x, top_y2).0;
            let total_b = count_fish(min_x, min_y, max_x, top_y2).1;
            let score = total_a - total_b;
            if score > best_score {
                best_score = score;
                best_coords = (min_x, min_y, max_x, top_y2);
                best_rects.push((top_x1, top_y1, top_x2, top_y2));
                expanded = true;
                continue;
            }
        }
    }

    // 将所有矩形合并后的顶点进行输出，确保相邻的点与 x 轴或 y 轴平行
    let mut vertices = Vec::new();
    let mut points = std::collections::HashSet::new();

    for &(x1, y1, x2, y2) in &best_rects {
        points.insert((x1, y1));
        points.insert((x2, y1));
        points.insert((x2, y2));
        points.insert((x1, y2));
    }

    // 将点按顺序连接，形成多边形
    let mut points_vec: Vec<_> = points.into_iter().collect();
    points_vec.sort_by_key(|&(x, y)| (x, y));
    vertices.extend(points_vec);

    println!("{}", vertices.len());
    for &(x, y) in &vertices {
        println!("{} {}", x, y);
    }
}
