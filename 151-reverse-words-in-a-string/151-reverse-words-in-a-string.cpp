class Solution {
public:
    string reverseWords(string str) {
        int n = str.length();
        string ans;
        int i = 0;

        while (i < n) 
        {
            //int j = i;

            // Skip multiple spaces
            while (i < n && str[i] == ' ') 
            {
                i++;
            }

            string currentWord;

            // Get the current word
            while (i < n && str[i] != ' ') 
            {
                currentWord.push_back(str[i]);
                i++;
            }

            // add current word in the ans with a space
            if (currentWord.length() != 0) 
            {
                ans.insert(0, currentWord + " ");
            }

            i = i + 1;
        }

        if (ans.length() == 0) 
        {
            return ans;
        }

        // remove the last space
        return ans.substr(0, ans.length() - 1);
    }
};