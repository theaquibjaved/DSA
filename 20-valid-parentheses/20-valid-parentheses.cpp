class Solution {
public:
    bool isValid(string s) {
        stack<char>st; 
        for(auto it: s) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                bool balancedBracket = (it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{');
                if(!balancedBracket) return false;
                //else return false;
            }
        }
        return st.empty(); 
    }
};