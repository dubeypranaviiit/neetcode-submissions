class Solution {
public:
   bool isSafe(int i,int j,int n,int m){
    if(i<0 || j<0) return 0;
    return true;
   }
    int count(int i,int j,vector<vector<int>>&dp){
        // base case
        if(i==0 && j==0)return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]= count(i-1,j,dp)+count(i,j-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return count(m-1,n-1,dp);
    }
};
