class Solution {
public:
    void dfs(int node,vector<vector<int>>&adjList, vector<bool>&visited) {
        visited[node] = 1;
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
   vector<bool>visited(n,false);
   vector<vector<int>>adj(n);
   for(auto &it :edges){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
   }
   int cnt=0;
   for(int i=0;i<n;i++){
       if(!visited[i]){
        cnt++;
        dfs(i,adj,visited);
       }
    }
   return cnt;
    }
};
