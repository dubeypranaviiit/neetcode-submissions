class Solution {
public:
    int minCost(int idx,vector<int>& cost,vector<int>& dp){
        if(idx<=1) return 0;
        if(dp[idx]!=-1) return dp[idx];
         int s1=cost[idx-1]+minCost(idx-1,cost,dp);
        int s2=cost[idx-2]+minCost(idx-2,cost,dp);
        return dp[idx]=min(s1,s2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int res=minCost(n,cost,dp);
        return res;
    }
};
