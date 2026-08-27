class Solution {
public: 
    int ans(int idx,vector<int>&nums,vector<int>&dp){
        if(idx<0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int nt=ans(idx-1,nums,dp);
       int take=nums[idx]+ans(idx-2,nums,dp);
        return dp[idx]=max(take,nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int>dp(n+1,-1);
        return ans(n-1,nums,dp);
    }
};
