class Solution {
public:
    int minJ(int idx,vector<int>&nums,vector<int>&dp){
        if(idx==nums.size()-1)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int minM=INT_MAX;
        for(int i=1;i<=nums[idx];i++){
             if (idx + i >= nums.size())
                break;
         int jp=minJ(idx+i,nums,dp);
         if (jp != INT_MAX)  
          minM=min(minM, 1+jp);
        }
        return dp[idx]=minM;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return minJ(0,nums,dp);
    }
};