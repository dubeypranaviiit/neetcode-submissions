class Solution {
public:
     int count(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
        // base case
        if(i==0 && j==0)return 1;
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]= count(i-1,j,dp,obstacleGrid)+count(i,j-1,dp,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
         if(obstacleGrid[0][0]==1) return 0;
    
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return count(m-1,n-1,dp,obstacleGrid);

    }
};