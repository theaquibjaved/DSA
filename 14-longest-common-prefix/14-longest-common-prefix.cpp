class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n = arr.size();
        string longestPrefix = "";

    for(int idx = 0; idx < arr[0].size(); ++idx)
    {
        // The variable ch is the character to be searched
        char ch = arr[0][idx];
        
        // A boolean value to check whether is it possible to insert ch in longest prefix or not.
        bool matched = true;

        for(int index = 1; index < n; ++index) 
        {   
            // Check if arr[index][idx] is equal to ch
            if (arr[index].size() < idx or arr[index][idx] != ch)
            {
                matched = false;
                break;
            }
        }

        // If matched is true,insert the character ch into longestPrefix
        if (matched)
        {
            longestPrefix += ch;
        }
        else
        {
            break;
        }
    }

    return longestPrefix;
    }
};