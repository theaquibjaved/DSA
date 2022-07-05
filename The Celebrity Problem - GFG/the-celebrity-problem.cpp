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
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       
        int p = 0, q = n-1; 

    // Finding celebrity.
    while(p < q) {
        if(knows(p, q, M)) {
            // This means p cannot be celebrity.
            p++;  
        }
        else {
            // This means q cannot be celebrity.
            q--; 
        }
    }

    int celeb = p;
    bool knowAny = false, knownToAll = true;

    // Verify whether the celebrity knows any other person.
    for(int i = 0; i < n; i++) {
        if(knows(celeb, i, M)) {
            knowAny = true;
            break;
        }
    }

    // Verify whether the celebrity is known to all the other person.
    for(int i = 0; i < n; i++) {
        if(i != celeb and !knows(i, celeb, M)) {
            knownToAll = false;
            break;
        }
    }

    if(knowAny or !knownToAll) {
        // If verificatin failed, then it means there is no celebrity at the party.
        celeb = -1;
    }

    return celeb;
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