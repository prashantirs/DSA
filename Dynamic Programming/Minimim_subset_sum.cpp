#include<bits/stdc++.h>
using namespace std;



void subsetSum(int arr[],int &n,int sum,vector<int>&v)
{
    
    bool t[n+1][sum+1];
    
    //initialization
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
        if(i==0) t[i][j]=false;
        if(j==0) t[i][j]=true;
        }
    }
    
    //code
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                //include
                t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];
            }
            else
            {
                //dont include
                t[i][j]=t[i-1][j];
            }
        }
    }
    
    for(int k=0;k<=sum/2;k++)
    {
        if(t[n][k]==true)
        {
            v.push_back(k);
        }
    }
}

int minDifference(int arr[], int n)  { 
    int sum=0; 
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    vector<int> v;
    subsetSum(arr,n,sum,v);
    int mini=INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        mini=min(mini,(sum-2*v[i])); // Range-2S1
    }
    return mini;
} 

int main(){
    int n=4;
    int arr[] = {1, 6, 11, 5};
    int ans= minDifference(arr, n); 
    cout<<ans;
 return 0;
}