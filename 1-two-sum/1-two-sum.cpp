class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		for(int j=i; j<numbers.size(); j++)
            if(numbers[i] + numbers[j] == target && i != j)
                result = {i, j};
	}
	return result;
    }
};