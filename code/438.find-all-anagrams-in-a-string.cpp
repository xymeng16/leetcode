#include <bits/stdc++.h>
using namespace std;
// start_marker
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    const int ls = s.size(), lp = p.size();
    std::cout << "ls: " << ls << ", lp: " << lp << std::endl;
    if (lp > ls) {
      return {};
    }

    vector<std::pair<char, int>> lcv(26);
    for (char c = 'a'; c <= 'z'; c++) {
      lcv.push_back({c, 0});
    }

    unordered_map pmap(lcv.begin(), lcv.end());
    for (const auto &c : p) {
      pmap[c]++;
    }

    unordered_map tmap(lcv.begin(), lcv.end());
    vector<int> ans;
    int start = 0, index = 0;

    while (start <= ls - lp) {
      while (index < lp) {
        std::cout << "start: " << start << ", index: " << index
                  << ", s[start + index]: " << s[start + index] << std::endl;
        tmap[s[start + index++]]++;
      }
      if (pmap == tmap) {
        ans.push_back(start);
      }
      for (char c = 'a'; c <= 'z'; c++) {
        tmap[c] = 0;
      }
      while (start <= ls - lp && pmap[s[++start]] == 0)
        ;
      index = 0;
    }

    return ans;
  }
};
// end_marker
int main() {
  Solution solution;
  auto ans = solution.findAnagrams(
      "asgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurd"
      "ncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbt"
      "jleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvh"
      "oimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkas"
      "gyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdnc"
      "wzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjl"
      "eurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoi"
      "mpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgy"
      "fqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwz"
      "xkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleu"
      "rdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimp"
      "btjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfq"
      "vhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxk"
      "asgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurd"
      "ncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbt"
      "jleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvh"
      "oimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkas"
      "gyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdnc"
      "wzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjl"
      "eurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoi"
      "mpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgy"
      "fqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwz"
      "xkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleu"
      "rdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimp"
      "btjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfq"
      "vhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxk"
      "asgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurd"
      "ncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbt"
      "jleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvh"
      "oimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkas"
      "gyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdnc"
      "wzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjl"
      "eurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoi"
      "mpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgy"
      "fqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwz"
      "xkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleu"
      "rdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimp"
      "btjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfq"
      "vhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxk"
      "asgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurd"
      "ncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbt"
      "jleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvh"
      "oimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkas"
      "gyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdnc"
      "wzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjl"
      "eurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoi"
      "mpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgy"
      "fqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwz"
      "xkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleu"
      "rdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimp"
      "btjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfq"
      "vhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxk"
      "asgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurd"
      "ncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbt"
      "jleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvh"
      "oimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkas"
      "gyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdnc"
      "wzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjl"
      "eurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoi"
      "mpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgy"
      "fqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwz"
      "xkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleu"
      "rdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimp"
      "btjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfq"
      "vhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxk"
      "asgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurd"
      "ncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbt"
      "jleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvh"
      "oimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkas"
      "gyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdnc"
      "wzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjl"
      "eurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoi"
      "mpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgy"
      "fqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwz"
      "xkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleu"
      "rdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimp"
      "btjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfq"
      "vhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxk"
      "asgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurd"
      "ncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbt"
      "jleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvh"
      "oimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkas"
      "gyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdnc"
      "wzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjl"
      "eurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoi"
      "mpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgy"
      "fqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwz"
      "xkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleu"
      "rdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimp"
      "btjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfq"
      "vhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxk"
      "asgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurd"
      "ncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbt"
      "jleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvh"
      "oimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkas"
      "gyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdnc"
      "wzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjl"
      "eurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoi"
      "mpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgy"
      "fqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwz"
      "xkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleu"
      "rdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimp"
      "btjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfq"
      "vhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxk"
      "asgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurd"
      "ncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbt"
      "jleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvh"
      "oimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkasgyfqvhoimpbtjleurdncwzxkas"
      "gyfqvhoimpbtjleurdncwzxk",
      "fqvhoimpbtjleurdncwzxk");
  for (const auto &v : ans) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}
