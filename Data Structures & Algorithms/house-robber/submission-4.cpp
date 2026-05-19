class Solution {
public:
  int ans(int idx,vector<int>&nums,vector<int>&dp){
   if(idx<0)return 0;
  if(dp[idx]!=-1) return dp[idx];
  int nt=ans(idx-1,nums,dp);
  int ta=ans(idx-2,nums,dp)+nums[idx];
  return dp[idx]=max(nt,ta);
  }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n+1,-1);
    //     int res=ans(n-1,nums,dp);
    //     return res;
    // }
       int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
       if(n==1) return nums[0];
      
       dp[0]=nums[0];
     dp[1] = max(nums[0], nums[1]);;
       for(int i=2;i<n;i++){
        int t=dp[i-2] +nums[i];
        int nt=dp[i-1];
        dp[i]=max(t,nt);
       }
        return dp[n-1];
    }
};
