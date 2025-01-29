#include<bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> result(2, 0);
         std::map<int, int> diffs;

         for (int i = 0; i < nums.size(); i++) {
            diffs.insert({target - nums[i], i});
         }

         for (const auto& [d ,i]: diffs) {
            if (i == nums.size() - 1) {
                return result; // impossible
            }

            if (auto search = diffs.find(d); search != diffs.end()) {
                result[0] = i;
                result[1] = search->second + 1;
                break;
            }
         }

         return result;    
    }
};
// end_marker
int main() {
    Solution solution;

}
