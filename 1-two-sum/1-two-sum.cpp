class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
	vector<int> res;
    unordered_map<int, int> map;
    
    for(int i=0; i < numbers.size(); i++){
        //int diff = target - numbers[i];
        if (map.find(target - numbers[i]) != map.end()) {
   		 res.emplace_back(i);
   		 res.emplace_back(map[target - numbers[i]]);
   		 //return res;
        }
        
        map[numbers[i]] = i;
    }
    return res;
    }
};
