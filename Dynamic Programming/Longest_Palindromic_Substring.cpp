#include<bits/stdc++.h>
using namespace std;

string lps(string s){
        int m=s.length();
        vector<vector<int>> t(m,vector<int>(m,-1));
        int maxi=1;
        int start=0;        
        int len=0;
        
        //initialzation
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                if(i==j){
                    t[i][j]=1;
                }else if(j==i+1){
                    if(s[i]==s[j]){
                        t[i][j]=1;
                        start=i;
                        maxi=2;
                    }else{
                        t[i][j]=0;
                    }
                }
            }
        }
        
         for(int len=3;len<=m;len++){
            for(int i=0;i<m-len+1;i++){
                int j=i+len-1;//j is end index
                if(s[i]==s[j] && t[i+1][j-1]==1){
                    
                    t[i][j]=1;
                    len=j-i+1;
                    
                    if(len>maxi){
                        maxi=len;
                        start=i;
                    }
                }else{
                    t[i][j]=0;
                }
            }
        }
        
    
        return s.substr(start,maxi);
    }