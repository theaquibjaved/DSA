class Solution {
public:
    // MOST OPTIMAL:
    int lengthOfLongestSubstring(string s) {
        
      vector<int> mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
// --------------------------------------------
//BETTER:
// int lengthOfLongestSubstring(string str) {
        
//        int maxans = INT_MIN;
//   unordered_set < int > set;
//   int l = 0;
//   for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
//   {
//     if (set.find(str[r]) != set.end()) //if duplicate element is found
//     {
//       while (l < r && set.find(str[r]) != set.end()) {
//         set.erase(str[l]);
//         l++;
//       }
//     }
//     set.insert(str[r]);
//     maxans = max(maxans, r - l + 1);
//   }
//   return maxans;
//     }
// };
