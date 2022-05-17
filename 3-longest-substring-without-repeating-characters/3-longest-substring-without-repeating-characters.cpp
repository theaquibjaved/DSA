class Solution {
public:
    //MOST OPTIMAL:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> mpp(256, -1);
           //   vector < int > mpp(256, -1);

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
// BETTER:
// int lengthOfLongestSubstring(string s) {
        
//         int  l = 0;
//         unordered_set<int> set;
//         int maxlen = INT_MIN;
        
//         for(int r = 0; r < s.length(); r++){
//             if(set.find(s[r]) != set.end()){
//                 set.erase(s[l]);
//                 l++;
//             }
//             set.insert(s[r]);
//             maxlen = max(maxlen, r - l + 1);
//         }
//         return maxlen;
//     }