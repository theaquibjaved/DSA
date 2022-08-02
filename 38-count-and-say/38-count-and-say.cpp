class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        if(n == 2)
            return "11";
        
        string res = countAndSay(n-1);
        string ans = "";
        int count = 1;
        
        for(int i = 1; i < res.size(); i++){
            
            bool newNumber = res[i] != res[i-1];
            if(newNumber){
                ans.push_back('0'+count);
                ans.push_back(res[i-1]);
                count = 1;
            }
            else{
                count++;
            }
            
            bool lastIndex = i == res.size()-1;
            if(lastIndex){
                ans.push_back('0'+count);
                ans.push_back(res[i]);
            }
        }
        
        return ans;
    }
};