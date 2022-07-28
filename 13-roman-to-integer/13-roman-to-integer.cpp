class Solution {
public:
    int romanToInt(string s) {
        
        
        unordered_map<char, int> roman =
        {{'I', 1},
         {'V', 5},
         {'X', 10},
         {'L', 50},
         {'C', 100},
         {'D', 500},
         {'M', 1000}};
        
        int res = 0;
       int n = s.length();
        
        for(int i = 0; i < n; i++){
            char cur = s[i];
            char nex = s[i+1];
            
            if(roman[cur] < roman[nex])
                res -= roman[cur];
            else
                res += roman[cur];
        }
        
        return res;
    }
};