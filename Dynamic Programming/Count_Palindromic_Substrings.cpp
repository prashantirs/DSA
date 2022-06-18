 #include<bits/stdc++.h>
using namespace std;

 int countSubstrings(string s) {
        
        int m=s.length();
        vector<vector<int>> t(m,vector<int>(m,-1));
        
        //initialization
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                if(i==j){
                    t[i][j]=1;
                }else if(j==i+1){
                    if(s[i]==s[j]){
                        t[i][j]=1;
                    }else{
                        t[i][j]=0;
                    }
                }
            }
        }
        
        for(int len=3;len<=m;len++){
            for(int i=0;i<m-len+1;i++){
                int j=i+len-1;//end index
                if(s[i]==s[j] && t[i+1][j-1]==1){
                    t[i][j]=1;
                }else{
                    t[i][j]=0;
                }
            }
        }
        
        
        
        
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                if(t[i][j]==1) count++;
            }
        }
        
        return count;
    }