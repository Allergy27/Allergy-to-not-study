//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1197.rs
//@data      2024/10/23 15:18:10
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}

struct UFset {
    fa: Vec<usize>,
    sz: usize,
}
impl UFset {
    fn new(n: usize) -> Self {
        Self {
            fa: (0..n).collect(),
            sz: n,
        }
    }
    fn find(&mut self, x: usize) -> usize {
        if x != self.fa[x] {
            self.fa[x] = self.find(self.fa[x]);
        }
        self.fa[x]
    }
    fn merge(&mut self, x: usize, y: usize) {
        let (fx, fy) = (self.find(x), self.find(y));
        if fx != fy {
            self.sz -= 1;
        }
        self.fa[fx] = fy;
    }
}

fn solve() {
    let (n, m) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut merge_list = vec![(0, 0); m];
    for x in &mut merge_list {
        *x = cin()
            .split_whitespace()
            .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    }
    let k = cin().parse::<usize>().unwrap();
    let mut attack = vec![0; k];
    let mut wait_for_merge = vec![Vec::new(); k];
    let mut check = vec![k; n];
    for i in 0..k {
        attack[i] = cin().parse::<usize>().unwrap();
        check[attack[i]] = i;
    }
    let mut qwq = UFset::new(n);
    qwq.sz-=k;
    for &(x, y) in &merge_list {
        if check[x] != k || check[y] != k {
            wait_for_merge[check[x].min(check[y])].push((x, y));
        } else {
            qwq.merge(x, y);
        }
    }
    let mut ans = vec![0; k];
    ans.push(qwq.sz);
    for i in (0..k).rev() {
        qwq.sz += 1;
        for &(x, y) in &wait_for_merge[i] {
            // println!("? {} {}", x, y);
            qwq.merge(x, y);
        }
        ans[i] = qwq.sz;
    }
    for x in &ans {
        println!("{}", x);
    }
}

