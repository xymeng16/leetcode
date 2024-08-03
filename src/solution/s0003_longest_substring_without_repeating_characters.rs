use std::cmp::max;
use std::collections::{HashMap, HashSet};

/**
 * [0003] Longest Substring Without Repeating Characters
 *
 * Given a string s, find the length of the longest <span data-keyword="substring-nonempty">substring</span> without repeating characters.
 *  
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 *  
 * Constraints:
 * 
 * 	0 <= s.length <= 5 * 10^4
 * 	s consists of English letters, digits, symbols and spaces.
 * 
 */
pub struct Solution {}

// problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// discuss: https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/?currentPage=1&orderBy=most_votes&query=

// submission codes start here

impl Solution {

    pub fn length_of_longest_substring(s: String) -> i32 {
        // dp[i] = if (s[i] not dup) { dp[i - 1] + 1 } else { i - index of last s[i] }
        if s.len() < 2 {
            return s.len() as i32;
        }
        let mut max: usize = 1;
        let mut map: HashMap<u8, usize> = HashMap::new();
        let s = s.as_bytes();
        let mut dp = vec![0; s.len()];
        dp[0] = 1;
        map.insert(s[0], 0);
        for i in 1..s.len() {
            if let Some(old_i) = map.insert(s[i], i) {
                // if no dup before then { i - old_i } else { dp[i - 1] + 1 }
                if dp[i - 1] >= i - old_i {
                    dp[i] = i - old_i;
                } else {
                    dp[i] = dp[i - 1] + 1;
                }
            } else {
                dp[i] = dp[i - 1] + 1;
            }
            if dp[i] > max {
                max = dp[i];
            }
        }

        max as i32
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0003_example_1() {
        let s = "abba".to_string();
        assert_eq!(Solution::length_of_longest_substring(s), 2);
    }
}
