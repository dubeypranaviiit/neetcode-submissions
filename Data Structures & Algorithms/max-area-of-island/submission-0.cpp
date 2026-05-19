class Solution {
public:

         void dfs(int r,int c,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis,int &area){

        int n = grid.size();
        int m = grid[0].size();
         if(r<0 || r>=n || c<0 || c>=m) return;
         if(grid[r][c] !=1 || vis[r][c] == 1) return;
        vis[r][c]=1;
        area++;
        dfs(r+1,c,grid,vis,area);
        dfs(r-1,c,grid,vis,area);
        dfs(r,c-1,grid,vis,area);
        dfs(r,c+1,grid,vis,area);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
            int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               
                if(!vis[i][j] && grid[i][j]==1){
                int area=0;
                dfs(i,j,grid,vis,area);
                  count=max(count,area);
                }
              
            }
        }
        return count;
    }

};
