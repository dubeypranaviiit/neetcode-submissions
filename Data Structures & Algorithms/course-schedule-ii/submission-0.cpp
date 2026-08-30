class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        queue<int>q;
        vector<int>ans;
        int processed=0;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
       for(int i=0;i<numCourses;i++){
        if(indegree[i]==0) q.push(i);
       }

    //    explore
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        // explore all it's neighbors
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
        processed++;
    }

    if(processed<numCourses)return {};
    return ans;
    }
};