class Solution {
public:
    vector<int> prevSmallerElement(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> pse(n);
        
        //for left smaller:
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
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //stack<int> st;
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        
        leftSmall = prevSmallerElement(heights);
        rightSmall = nextSmallerElement(heights);
        
//         //for left smaller:
//         for(int i = 0; i < n; i++){
//             while(!st.empty() && heights[st.top()] >= heights[i])
//                 st.pop();
            
//             if(!st.empty())
//                 leftSmall[i] = st.top() + 1;
            
//             else
//                 leftSmall[i] = 0;
                
//             st.push(i);
//         }
        
        //clear the stack to re-use:
        // while(!st.empty())
        //     st.pop();
        
//         //for right smaller:
//         for(int i = n-1; i >= 0; i--){
//             while(!st.empty() && heights[st.top()] >= heights[i])
//                 st.pop();
            
//             if(!st.empty())
//                 rightSmall[i] = st.top() - 1;
            
//             else
//                 rightSmall[i] = n - 1;
                
//             st.push(i);
//         }
        
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