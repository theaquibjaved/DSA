class Solution {
public:
    string decodeMessage(string key, string message) {    
            map<char,char>mp;
            char temp  = 'a';
        
             int n = key.length();
        
            for(int i = 0; i < n; i++) {
                if(key[i] != ' ' && mp.find(key[i]) == mp.end()) {
                    mp[key[i]] = temp;
                    temp++;
                }

            }

            string res = "";
            int m = message.length();

            for(int i = 0; i < m; i++) {
                if(message[i] != ' '){
                    res+= mp[message[i]];
                }
                else {
                    res+= " ";
                }
            }

            return res;        
    }
};