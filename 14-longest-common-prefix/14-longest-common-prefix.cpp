class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string longestPrefix = "";
        
        int firstStringSize = strs[0].size();
        
        for(int i = 0; i < firstStringSize; i++){
            char ch = strs[0][i];
            bool match = true;
            for(int j = 1; j < n; j++){
                bool notMatchingWithRest = strs[j].size() < i || ch != strs[j][i];
                if(strs[j].size() < i or strs[j][i] != ch){
                    match = false;
                    break;
                }
            }
            
            if(!match)
                break;
            else
                longestPrefix.push_back(ch);
        }
        
        return longestPrefix;
    }
};