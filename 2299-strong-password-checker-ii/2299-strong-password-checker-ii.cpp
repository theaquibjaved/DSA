class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        
        bool lc = false, uc = false, dig = false, spl = false, adj = true, len = false;
        
        int n = password.size();
        if(n >= 8)
            len = true;
        
        for(int i = 0; i < n; i++){
            
            bool isspl = password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || 
                   password[i] == '&' || password[i] == '%' || password[i] == '^' || password[i] == '*' ||
                   password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+';
            
            if(isupper(password[i]))
                uc = true;
            
            else if(islower(password[i]))
                lc = true;
            
            else if(isspl)
                spl = true;
            
            else if(isdigit(password[i]))
                dig = true;
        }
        
        for(int i = 0; i < n-1; i++){
            if(password[i] == password[i+1])
                adj = false;
        }
        
        if(lc && uc && dig && spl && adj && len && adj)
            return true;
        
        return false;
    }
};