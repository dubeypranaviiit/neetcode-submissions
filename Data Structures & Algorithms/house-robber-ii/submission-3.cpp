class Solution {
public: 
    int ans1(int idx,vector<int>&nums,vector<int>&dp){
        if(idx<1)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int nt=ans1(idx-1,nums,dp);
       int take=nums[idx]+ans1(idx-2,nums,dp);
        return dp[idx]=max(take,nt);
    }
     int ans2(int idx,vector<int>&nums,vector<int>&dp){
        if(idx<0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int nt=ans2(idx-1,nums,dp);
       int take=nums[idx]+ans2(idx-2,nums,dp);
        return dp[idx]=max(take,nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int sum=0;
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(ans1(n-1,nums,dp1),ans2(n-2,nums,dp2));
    }
};


