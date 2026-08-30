class Solution {
public:
   bool dfs(int node, int parent, vector<vector<int>>& adj,
             vector<bool>& visited) {
        
        visited[node] = true;

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                if (dfs(nei, node, adj, visited))
                    return true;
            }
            else if (nei != parent) {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int components = 0;
        bool cycle = false;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;

                if (dfs(i, -1, adj, visited)) {
                    cycle = true;
                }
            }
        }
        return components == 1 && !cycle;
    }
};
