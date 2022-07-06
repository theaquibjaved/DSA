class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
   
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        
        leftSmall = prevSmallerElement(heights);
        rightSmall = nextSmallerElement(heights);        

        //calculate the area
        int maxArea = 0, currArea, width;
        for(int i = 0; i < n; i++){
            width = rightSmall[i] - leftSmall[i] + 1;
            currArea = width * heights[i];
            
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
    
    vector<int> prevSmallerElement(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> pse(n);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(!st.empty())
                pse[i] = st.top() + 1;
            
            else
                pse[i] = 0;
                
            st.push(i);
        }
        return pse;
    }
    
    vector<int> nextSmallerElement(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n);
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(!st.empty())
                nse[i] = st.top() - 1;
            
            else
                nse[i] = n - 1;
                
            st.push(i);
        }
        return nse;
    }
    
    
};