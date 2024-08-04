/**
 * [0004] Median of Two Sorted Arrays
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 *  
 * Example 1:
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Example 2:
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 *  
 * Constraints:
 * 
 * 	nums1.length == m
 * 	nums2.length == n
 * 	0 <= m <= 1000
 * 	0 <= n <= 1000
 * 	1 <= m + n <= 2000
 * 	-10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 */
pub struct Solution {}

// problem: https://leetcode.com/problems/median-of-two-sorted-arrays/
// discuss: https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/?currentPage=1&orderBy=most_votes&query=

// submission codes start here

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (mut i, mut j, l1, l2) = (0, 0, nums1.len(), nums2.len());
        if l1 == 0 {
            if l2 % 2 == 0 {
                return (nums2[(l2 / 2) - 1] + nums2[l2 / 2]) as f64 / 2.0;
            } else {
                return nums2[l2 / 2] as f64;
            }
        }
        if l2 == 0 {
            if l1 % 2 == 0 {
                return (nums1[(l1 / 2) - 1] + nums1[l1 / 2]) as f64 / 2.0;
            } else {
                return nums1[l1 / 2] as f64;
            }
        }
        let sum_l = l1 + l2;
        let i_median = sum_l / 2;
        let mut c = 0;
        let (mut t1, mut t2) = (0, 0);
        loop {
            if i < l1 && j < l2 {
                if nums1[i] < nums2[j] {
                    t2 = nums1[i];
                    i += 1;
                } else {
                    t2 = nums2[j];
                    j += 1;
                }
            } else if i >= l1 && j < l2 {
                // nums1 done
                t2 = nums2[j];
                j += 1;
            } else if i < l1 && j >= l2 {
                // nums2 done
                t2 = nums1[i];
                i += 1;
            }
            c += 1;
            if c > i_median {
                break;
            }
            t1 = t2;
        }
        if sum_l % 2 == 0 {
            (t1 + t2) as f64 / 2.0
        } else {
            t2 as f64
        }
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0004_example_1() {
        assert_eq!(Solution::find_median_sorted_arrays(vec![1, 3], vec![2]), 2.0);
    }

    #[test]
    fn test_0004_example_2() {
        assert_eq!(Solution::find_median_sorted_arrays(vec![1, 2], vec![3, 4]), 2.5);
    }
}
