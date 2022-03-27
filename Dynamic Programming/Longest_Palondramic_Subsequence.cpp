#include<iostream>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string p=string(s.rbegin(),s.rend());
        
        int n=s.length();
        
        int t[n+1][n+1];
        //initialization
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
                if(s[i-1]==p[j-1])
                {
                    //include
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    //check more cases for max
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        
        return t[n][n];
    }
};

int main(){
 
         
  
 return 0;
}