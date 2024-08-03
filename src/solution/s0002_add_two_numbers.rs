/**
 * [0002] Add Two Numbers
 *
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *  
 * Example 1:
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg" style="width: 483px; height: 342px;" />
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * Example 2:
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * Example 3:
 * 
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 
 *  
 * Constraints:
 * 
 * 	The number of nodes in each linked list is in the range [1, 100].
 * 	0 <= Node.val <= 9
 * 	It is guaranteed that the list represents a number that does not have leading zeros.
 * 
 */
pub struct Solution {}
use crate::util::linked_list::{ListNode};

// problem: https://leetcode.com/problems/add-two-numbers/
// discuss: https://leetcode.com/problems/add-two-numbers/discuss/?currentPage=1&orderBy=most_votes&query=

// submission codes start here

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
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = Box::new(ListNode::new(0));
        let mut current = &mut head;
        let mut carry: i32 = 0;
        let mut l1 = l1;
        let mut l2 = l2;


        loop {
            let l1v = match l1 {
                Some(ref node) => node.val,
                None => 0,
            };
            let l2v = match l2 {
                Some(ref node) => node.val,
                None => 0,
            };
            let mut sum = l1v + l2v + carry;
            carry = 0;
            if sum >= 10 {
                carry = 1;
                sum %= 10;
            }
            current.val = sum;

            l1 = l1.unwrap_or(Box::new(ListNode::new(0))).next;
            l2 = l2.unwrap_or(Box::new(ListNode::new(0))).next;
            if l1.is_none() && l2.is_none() {
                if carry == 1 {
                    current.next = Some(Box::new(ListNode::new(carry)));
                }
                break;
            }
            current.next = Some(Box::new(ListNode::new(0)));
            current = current.next.as_mut().unwrap();
        }
        Some(head)
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0002_example_1() {
    }
}
