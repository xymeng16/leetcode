#include <bits/stdc++.h>
using namespace std;
// start_marker
#define AVG(a, b) (((a) + (b)) / 2.0)
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    const int m = nums1.size();
    const int n = nums2.size();

    if (m > n) {
      return this->findMedianSortedArrays(nums2, nums1);
    }

    /*
     * 0(low) - m(high) - n
     * l in total
     */
    int low = 0, high = m;
    int l = m + n;

    while (low <= high) {
      int pivot1 = (low + high) / 2;
      int pivot2 = (l + 1) / 2 - pivot1;

      int maxLeft1 = (pivot1 == 0) ? INT_MIN : nums1[pivot1 - 1];
      int minRight1 = (pivot1 == m) ? INT_MAX : nums1[pivot1];

      int maxLeft2 = (pivot2 == 0) ? INT_MIN : nums2[pivot2 - 1];
      int minRight2 = (pivot2 == n) ? INT_MAX : nums2[pivot2];

      // truths: maxLeft1 <= minRight1, maxLeft2 <= minRight2
      // so we simply check if maxLeft1 <= minRight2 && maxLeft2 <= minRight1
      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
        // we found the correct partitions
        if (l % 2) {
          return std::max(maxLeft1, maxLeft2);
        } else {
          return (std::max(maxLeft1, maxLeft2) +
                  std::min(minRight1, minRight2)) /
                 2.0;
        }
      } else if (maxLeft1 > minRight2) {
        high = pivot1 - 1;
      } else {
        low = pivot1 + 1;
      }
    }

    return -1; // impossible
  }
};
// end_marker
int main() {
  Solution solution;
  // vector<int> nums1({0, 0}), nums2({0, 0});
  // vector<int> nums1({1, 3}), nums2({2});
  vector<int> nums1({1, 2, 2}), nums2({1, 2, 3});
  std::cout << solution.findMedianSortedArrays(nums1, nums2);
}
