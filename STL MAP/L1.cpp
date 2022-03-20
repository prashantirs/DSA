#include<iostream>

//STL
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans(k);
        //creating unordered map and mapping with nums
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        
        // creating max heap i.e. priority queue
        priority_queue<pair<int,int>> pq;
        
        //traversing unordered map and pushing in max heap
        unordered_map<int,int> ::iterator itr;
        for(itr=umap.begin();itr!=umap.end();itr++)
        {
            pq.push(make_pair(itr->second,itr->first));
        }
        
        for(int j=0;j<k;j++)
        {
            ans[j]=pq.top().second;
            pq.pop();
        }

        return ans;
    }
};
 
int main(){
 
         
  
 return 0;
}

