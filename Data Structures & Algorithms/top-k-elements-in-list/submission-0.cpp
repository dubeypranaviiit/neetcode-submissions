class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==0)return {};
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(k>0){
            int top=pq.top().second;
            pq.pop();
            ans.push_back(top);
            k--;
        }
        return ans;
    }
};
