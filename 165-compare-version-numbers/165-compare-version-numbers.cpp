class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        
        int vnum1 = 0, vnum2 = 0;
        int i = 0, j = 0;
        
        while(i < n || j < m){
            
            while(i < n && version1[i] != '.'){
                vnum1 = vnum1*10 + (version1[i] - '0');
                i++;
            }
            
            while(j < m && version2[j] != '.'){
                vnum2 = vnum2*10 + (version2[j] - '0');
                j++;
            }
            
            if(vnum1 < vnum2)
                return -1;
            if(vnum1 > vnum2)
                return 1;
            
            vnum1 = vnum2 = 0; //for next level
            i++;
            j++;
        }
        
        return 0;
    }
};