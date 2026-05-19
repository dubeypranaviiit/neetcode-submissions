class Solution {
public:
  int ans(int idx,vector<int>&nums,vector<int>&dp){
   if(idx<1)return 0;
  if(dp[idx]!=-1) return dp[idx];
  int nt=ans(idx-1,nums,dp);
  int ta=ans(idx-2,nums,dp)+nums[idx];
  return dp[idx]=max(nt,ta);
  }
    int ans2(int idx,vector<int>&nums,vector<int>&dp){
   if(idx<0)return 0;
  if(dp[idx]!=-1) return dp[idx];
  int nt=ans2(idx-1,nums,dp);
  int ta=ans2(idx-2,nums,dp)+nums[idx];
  return dp[idx]=max(nt,ta);
  }
    int rob(vector<int>& nums) {
     int n=nums.size();
     if(n==1)return nums[0];
     if(n==2) return max(nums[0],nums[1]);
     vector<int>dp(n+1,-1);
     int s1=ans(n-1,nums,dp);
        vector<int>dp2(n+1,-1);
     int s2=ans2(n-2,nums,dp2);

     return max(s1,s2);
    }
};
