/*
 * @lc app=leetcode.cn id=2487 lang=rust
 *
 * [2487] 从链表中移除节点
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
    pub fn remove_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut qwq = Vec::new();
        while let Some(x)=head.as_ref().next.take(){
            while qwq.len()!=0&&x>qwq[qwq.len()-1]{
                qwq.pop();
            }
            qwq.push(x);
        }
        println!("{:?}",qwq);
        head
    }
}
// @lc code=end

