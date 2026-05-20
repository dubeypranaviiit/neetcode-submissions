class Solution {
public:

    void dfs(vector<vector<int>>& grid, int r, int c, int dist) {

        int n = grid.size();
        int m = grid[0].size();

        // boundary check
        if(r < 0 || c < 0 || r >= n || c >= m)
            return;

        // wall
        if(grid[r][c] == -1)
            return;

        // if already smaller distance exists
        if(dist > grid[r][c])
            return;

        // update distance
        grid[r][c] = dist;

        dfs(grid, r+1, c, dist+1);
        dfs(grid, r-1, c, dist+1);
        dfs(grid, r, c+1, dist+1);
        dfs(grid, r, c-1, dist+1);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(grid[i][j] == 0) {

                    dfs(grid, i, j, 0);
                }
            }
        }
    }
};