#include<bits/stdc++.h>
using namespace std;


//Longest common subsequence
class Solution {
public:
    int longestCommonSubseq(string X,string Y) {
        
        
        int m=X.length();
        int n=Y.length();
        
        int t[m+1][n+1];
        //initialization
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(X[i-1]==Y[j-1])
                {
                    //include
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    //check more cases for max
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        
        return t[m][n];
    }
};

 
int main(){

  string X,Y;
  cin>>X>>Y;        
 
  //input X: abcdgh
  //      Y: abedfhr

  //output--> 4

  Solution obj;
  int ans=obj.longestCommonSubseq(X,Y);
  cout<<ans;
 
 return 0;
}