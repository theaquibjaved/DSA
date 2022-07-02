class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int leftSmall[n], rightSmall[n];
        
        //for left smaller:
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(!st.empty())
                leftSmall[i] = st.top() + 1;
            
            else
                leftSmall[i] = 0;
                
            st.push(i);
        }
        
        //clear the stack to re-use:
        while(!st.empty())
            st.pop();
        
        //for right smaller:
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(!st.empty())
                rightSmall[i] = st.top() - 1;
            
            else
                rightSmall[i] = n - 1;
                
            st.push(i);
        }
        
        //calculate the area
        int maxArea = 0, currArea, width;
        for(int i = 0; i < n; i++){
            width = rightSmall[i] - leftSmall[i] + 1;
            currArea = width * heights[i];
            
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
};