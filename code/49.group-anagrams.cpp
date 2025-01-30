#include<bits/stdc++.h>
using namespace std;
// start_marker

struct vector_hash {
  template <class T1, class T2>
  std::size_t operator () (std::pair<T1, T2> const &v) const
  {
    return std::hash<T1>()(v.size());
  }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      // unordered_map<char, unordered_set<int>> ht;
      // for (int i = 0; i < strs.size(); i++) {
      //   for (int j = 0; j < strs[i].size(); j++) {
      //     ht[strs[i][j]].insert(i);
      //   }
      // }
      vector<vector<string>> result;

      // auto sorted_strs = strs;
      // for (auto &str: sorted_strs) {
      //   std::sort(str.begin(), str.end());
      // }
      //
      // unordered_map<string, unordered_set<int>> hashmap;
      // for (int i = 0; i < sorted_strs.size(); i++) {
      //   hashmap[sorted_strs[i]].insert(i);
      // }
      // for (const auto& [k, v]: hashmap) {
      //   vector<string> t;
      //   for (const auto& i: v) {
      //     t.push_back(strs[i]);
      //   }
      //   result.push_back(t);
      // }
      //
      unordered_map<string, vector<string>> map;

        for (auto str: strs) {
            auto sorted_str = str;
            std::sort(sorted_str.begin(), sorted_str.end());
            auto search = map.find(sorted_str);
            if (search == map.end()) {
                map[sorted_str] = {str};
            } else {
                map[sorted_str].push_back(str);
            }
        }

        for (const auto& [k, v]: map) {
            result.push_back(v);
        }

      return result;
    }
};
// end_marker
int main() {
    Solution solution;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto result = solution.groupAnagrams(strs);
    for (auto &v: result) {
      for (auto &s: v) {
        cout << s << ' ';
      }
      cout << endl;
    }

  return 0;
}
