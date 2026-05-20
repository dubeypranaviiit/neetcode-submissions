class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;
        int time = 0;

        // push ALL rotten oranges
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(grid[i][j] == 2) {
                    q.push({i,j});
                }

                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        while(!q.empty() && fresh > 0) {

            int sz = q.size();

            // one BFS level = one minute
            for(int i=0;i<sz;i++) {

                auto [r,c] = q.front();
                q.pop();

                for(auto &d : dir) {

                    int nr = r + d.first;
                    int nc = c + d.second;

                    if(nr>=0 && nc>=0 &&
                       nr<n && nc<m &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr,nc});
                    }
                }
            }

            time++;
        }

        return fresh == 0 ? time : -1;
    }
};