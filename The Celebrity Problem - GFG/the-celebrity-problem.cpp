// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    bool knows(int a, int b, vector<vector<int> >& M){
        if(M[a][b] == 1)
            return true;
        return false;
    }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
       
        int i = 0, j = n - 1;
        while (i < j) {
            if (knows(j, i, M))
                j--;
            else // j doesnt know i so i cant be celebrity
                i++;
        }
        // i points to our celebrity candidate
        int candidate = i;

        
        for (i = 0; i < n; i++) {
            bool notCeleb = i != candidate && (!knows(i, candidate, M) || knows(candidate, i, M));
                if (notCeleb)
                    return -1;
        }
         
        return candidate;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends