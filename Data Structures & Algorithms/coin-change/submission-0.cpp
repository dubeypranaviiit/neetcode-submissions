class Solution {
public:
int ans=INT_MAX;
int f(int  idx, int amt,vector<int>&coins,vector<vector<int>>&dp){
    if(amt==0) return 0;
    if(amt<0 || idx>=coins.size()) return 1e9;
    if(idx==coins.size()-1){
        if(amt % coins[idx]==0)return amt/coins[idx];
        else return 1e9;
    }
    if(dp[idx][amt]!=-1) return dp[idx][amt];
    int ctaken1=INT_MAX;
    if(amt-coins[idx]>=0){
    ctaken1=1+f(idx,amt-coins[idx],coins,dp);
    }
    int ctaken2=f(idx+1,amt,coins,dp);

    return dp[idx][amt]=min(ctaken1,ctaken2);

}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(0,amount,coins,dp);
        return ans==1e9?-1:ans;
    }
};