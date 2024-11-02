/*
 * @lc app=leetcode.cn id=3165 lang=rust
 * @lcpr version=20002
 *
 * [3165] 不包含相邻元素的子序列的最大和
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
const MOD: i64 = 1_000_000_007;

impl Solution {
    pub fn maximum_sum_subsequence(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut st = SegmentTree::new(n);
        st.init(&nums);

        let mut ans = 0;
        for q in queries {
            let idx = q[0] as usize;
            let val = q[1];
            st.update(idx, val);
            ans = (ans + st.query(0)) % MOD;
        }
        ans as _
    }
}

#[derive(Debug, Clone)]
struct SegmentTree {
    tree: Vec<[i64; 4]>,
    n: usize,
}

impl SegmentTree {
    pub fn new(n: usize) -> Self {
        Self {
            tree: vec![[0, 0, 0, 0]; n << 2],
            n,
        }
    }
    pub fn init(&mut self, arr: &[i32]) {
        self.internel_init(arr, 0, 0, self.n - 1);
    }

    pub fn update(&mut self, pos: usize, val: i32) {
        self.internel_update(0, 0, self.n - 1, pos, val as i64);
    }

    pub fn query(&self, x: usize) -> i64 {
        self.tree[x][3]
    }

    fn internel_init(&mut self, arr: &[i32], idx: usize, l: usize, r: usize) {
        if l == r {
            self.tree[idx] = [0, 0, 0, arr[l].max(0) as i64];
            return;
        }
        let mid = (l + r) >> 1;
        self.internel_init(arr, idx << 1 | 1, l, mid);
        self.internel_init(arr, idx + 1 << 1, mid + 1, r);
        self.merge(idx);
    }

    fn internel_update(&mut self, idx: usize, l: usize, r: usize, pos: usize, val: i64) {
        if l == r {
            self.tree[idx] = [0, 0, 0, val.max(0)];
            return;
        }
        let mid = (l + r) >> 1;
        if pos <= mid {
            self.internel_update(idx << 1 | 1, l, mid, pos, val);
        } else {
            self.internel_update(idx + 1 << 1, mid + 1, r, pos, val);
        }
        self.merge(idx);
    }
    fn merge(&mut self, idx: usize) {
        let l = idx * 2 + 1;
        let r = idx * 2 + 2;
        self.tree[idx][0] =
            (self.tree[l][0] + self.tree[r][2]).max(self.tree[l][1] + self.tree[r][0]);
        self.tree[idx][1] =
            (self.tree[l][0] + self.tree[r][3]).max(self.tree[l][1] + self.tree[r][1]);
        self.tree[idx][2] =
            (self.tree[l][2] + self.tree[r][2]).max(self.tree[l][3] + self.tree[r][0]);
        self.tree[idx][3] =
            (self.tree[l][2] + self.tree[r][3]).max(self.tree[l][3] + self.tree[r][1]);
    }
}
// @lc code=end

/*
// @lcpr case=start
// [0,3,3,3,1,-2]\n[[4,0],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1,-1,-1]\n[[0,-1],[0,-1],[0,-1],[0,-1],[0,-1],[0,-1],[0,-1]]\n
// @lcpr case=end

 */
