//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/max_flow.rs
//@data      2024/11/09 15:35:24
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
/*
struct MaxFlow<T> {
    n: usize,
    qwq: Vec<Vec<(T, usize)>>,
}
impl<T> MaxFlow<T>
where
    T: Clone + Copy + From<usize> + std::ops::Neg<Output = T> + Into<usize>,
{
    fn new(n: usize) -> Self {
        MaxFlow {
            n,
            qwq: vec![Vec::new(); n],
        }
    }
    fn add(&mut self, i: usize, j: usize, w: T) {
        self.qwq[i].push((w, j));
    }
    //求最大流

    fn dinic(&self, start: usize, end: usize) {
        let mut max_flow = 0;

        //寻找level graph
        let bfs = |lev: &mut Vec<Vec<(T, usize)>>, f_ed: &mut Vec<bool>| {
            let mut que = std::collections::VecDeque::new();
            que.push_back((start, 0));
            while let Some((fa, level)) = que.pop_front() {
                for (w, tmp) in &self.qwq[fa] {
                    if !f_ed[fa] {
                        lev[fa].push((*w, *tmp));
                        que.push_back((*tmp, level + 1));
                        f_ed[*tmp] = true;
                    }
                }
            }
            f_ed[end]
        };

        loop {
            //构建level graph
            let mut lev = vec![Vec::new(); self.n];
            let mut f_ed = vec![false; self.n];
            //无法构建level graph
            if !bfs(&mut lev, &mut f_ed) {
                break;
            }

            //根据level graph 求residual graph
            let mut stk = Vec::new();
            stk.push(vec![start]);
            while let Some(cur) = stk.pop() {
                for (w, tmp) in &lev[*cur.last().unwrap()] {
                    if *tmp == end {}
                }
            }
        }
    }
}
*/
fn solve() {}
