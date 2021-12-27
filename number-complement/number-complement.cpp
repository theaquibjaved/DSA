class Solution {
public:
    int findComplement(int num) {
        int c = 1;
        
        while(num > c)
            c = (c * 2) + 1;
        
        return c - num;
        
    }
};