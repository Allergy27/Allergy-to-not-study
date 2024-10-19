/*
 * @lc app=leetcode.cn id=2181 lang=rust
 *
 * [2181] 合并零之间的节点
 */

// @lc code=start
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut s = 0;
        let mut ans = Box::new(ListNode::new(0));
        let mut tile = &mut ans;
        let mut cur = head.unwrap().next();
        while let Some(node) = cur.take() {
            if node.val != 0 {
                s += node.val;
            } else {
                tail.next = Box::new(List::new(s));
                tail = tail.as_mut().next.unwrap();
                s = 0;
            }

        }
    }
}
// @lc code=end
