class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int num1 = -1, num2 = -1;
        int count1 = 0, count2 = 0;
        int n = nums.size();
        
        for(auto element : nums){
            
            if(element == num1)
                count1++;
            else if(element == num2)
                count2++;
            
            else if(count1 == 0){
                num1 = element;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = element;
                count2 = 1;
            }
            
            else{
                count1--;
                count2--;
            }                
        }
        
        vector<int> ans;
        count1 = 0;
        count2 = 0;
        
        for(auto element : nums){
            if(element == num1) count1++;
            else if(element == num2) count2++;
        }
        
        if(count1 > n/3) ans.push_back(num1);
        if(count2 > n/3) ans.push_back(num2);
        
        return ans;
    }
};