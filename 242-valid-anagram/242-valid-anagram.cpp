class Solution {
public:
    #define NO_OF_CHARS 256
    
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(n != m)
            return false;
        
        int hash[NO_OF_CHARS] = {0};
        
        for(int i = 0; i < n; i++){
            hash[s[i]]++;
            hash[t[i]]--;
            
            // if(hash[i] == 0)
            //     return false;
        }
        
        for(int i = 0; i < NO_OF_CHARS; i++){
            if(hash[i])
                return false;
        }
        
        return true;
    }
};