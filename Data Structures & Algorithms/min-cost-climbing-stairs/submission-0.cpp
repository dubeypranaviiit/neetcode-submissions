class Solution {
public:
    int minCost(int n,vector<int>&cost,vector<int>&dp){
        if(n<0)return 0;
        if(n==0 || n==1)return cost[n];
        if(dp[n]!=-1)return dp[n];
        int step1=minCost(n-1,cost,dp);
        int step2=minCost(n-2,cost,dp);
        return dp[n]= cost[n]+min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(minCost(n-1,cost,dp),minCost(n-2,cost,dp));
    }
};
