class Solution {
public: 
    bool bfs( unordered_map<int , vector<int>>&adj , int n ,  vector<int>&indegree){
        int count = 0;
           queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        while( !q.empty()){
            int u = q.front();
            q.pop();
            for( auto &v : adj[u]){
                //remember 
                indegree[v]--;
                if( indegree[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }
        return count == n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
            unordered_map<int , vector<int>>adj;
            vector<int>indegree( numCourses , 0);
            for( vector<int>v : pre){
                 int a = v[0];
                 int b = v[1];
                 adj[b].push_back(a);
                indegree[a]++;
            }
          queue<int>q;
          return bfs(adj , numCourses , indegree  );

    }
};