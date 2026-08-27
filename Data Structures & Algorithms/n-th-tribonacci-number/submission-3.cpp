class Solution {
public:
   int fibo3(int n,vector<int>&dp){
    if(n<0)return 0;
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fibo3(n-1,dp)+fibo3(n-2,dp)+fibo3(n-3,dp);
   }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return fibo3(n,dp);
    }
};