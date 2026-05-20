class Solution {
public:

    // void dfs(vector<vector<int>>& grid, int r, int c, int dist) {

    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if(r < 0 || c < 0 || r >= n || c >= m)
    //         return;
    //     if(grid[r][c] == -1)
    //         return;
    //     if(dist > grid[r][c])
    //         return;

        
    //     grid[r][c] = dist;

    //     dfs(grid, r+1, c, dist+1);
    //     dfs(grid, r-1, c, dist+1);
    //     dfs(grid, r, c+1, dist+1);
    //     dfs(grid, r, c-1, dist+1);
    // }

    // void islandsAndTreasure(vector<vector<int>>& grid) {

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     for(int i=0;i<n;i++) {
    //         for(int j=0;j<m;j++) {

    //             if(grid[i][j] == 0) {

    //                 dfs(grid, i, j, 0);
    //             }
    //         }
    //     }
    // }
    
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
         queue<pair<int,int>> q;

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

        if(grid[i][j] == 0){
            q.push({i,j});
        }
    }
}

vector<pair<int,int>> dir = {
    {1,0},{-1,0},{0,1},{0,-1}
};

while(!q.empty()){

    auto [r,c] = q.front();
    q.pop();

    for(auto &d : dir){

        int nr = r + d.first;
        int nc = c + d.second;

        if(nr>=0 && nc>=0 &&
           nr<n && nc<m &&
           grid[nr][nc] == 2147483647){

            grid[nr][nc] = grid[r][c] + 1;

            q.push({nr,nc});
        }
    }
}
    }
};