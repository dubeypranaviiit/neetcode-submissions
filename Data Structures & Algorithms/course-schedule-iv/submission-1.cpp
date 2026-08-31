class Solution {
public:

    void dfs(int node, int start,
             vector<vector<int>>& adj,
             vector<vector<bool>>& isPrereq) {

        for (auto next : adj[node]) {

            if (isPrereq[start][next])
                continue;

            isPrereq[start][next] = true;

            dfs(next, start, adj, isPrereq);
        }
    }

    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);

        // prerequisite -> course
        for (auto p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        // isPrereq[u][v] = true
        // means u is prerequisite of v
        vector<vector<bool>> isPrereq(
            numCourses,
            vector<bool>(numCourses, false)
        );

        // Find all reachable courses from every course
        for (int i = 0; i < numCourses; i++) {
            dfs(i, i, adj, isPrereq);
        }

        // Answer queries
        vector<bool> ans;

        for (auto q : queries) {
            int u = q[0];
            int v = q[1];

            ans.push_back(isPrereq[u][v]);
        }

        return ans;
    }
};