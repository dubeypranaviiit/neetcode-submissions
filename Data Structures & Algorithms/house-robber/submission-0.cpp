class Solution {
public:
  int ans(int idx,vector<int>&nums,vector<int>&dp){
   if(idx<0)return 0;
  if(dp[idx]!=-1) return dp[idx];
  int nt=ans(idx-1,nums,dp);
  int ta=ans(idx-2,nums,dp)+nums[idx];
  return dp[idx]=max(nt,ta);
  }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int res=ans(n-1,nums,dp);
        return res;
    }
};
