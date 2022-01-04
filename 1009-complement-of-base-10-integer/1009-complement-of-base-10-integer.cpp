class Solution {
public:
    int bitwiseComplement(int n) {
        
        int comp = 1;
        
        while(n > comp)
            comp = (comp << 1) | 1;    // comp = (comp*2) + 1;
        
        return comp^n;      //return comp-n;
    }
};