// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        
        // int length[n]={1,2,3,4,5,6,7,8};
        vector<int> length(n);
        for(int i=0;i<n;i++)
        {
            length[i]=i+1;
        }
        
        int t[n+1][n+1];//N=8
        
        //initilization
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        
          for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(length[i-1]<=j)
                {
                    //include or dont include
                    t[i][j]=max((price[i-1]+t[i][j-length[i-1]]) ,(t[i-1][j]));
                }else{
                    //dont include
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][n];
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  
 
