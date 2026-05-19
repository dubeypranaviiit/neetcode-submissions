class Solution {
public:
    int dway(int idx,vector<int>&dp){
        if(idx<=1) return 1;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=dway(idx-1,dp)+dway(idx-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int res=dway(n,dp);
        return res;
    }
};
