class Solution {
public:
   void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || visited[i][j])return;
         visited[i][j]=true;
        //  explore all the four direction
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);
   }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
               cnt++;
               dfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};
