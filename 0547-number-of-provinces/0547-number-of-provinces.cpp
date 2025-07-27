class Solution {
public: 
      void bfs(vector<vector<int>>& adj, int curr, vector<bool>& visited) {
        int n = adj.size();
        queue<int> q;
        q.push(curr);
        visited[curr] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbour = 0; neighbour < n; ++neighbour) {
                if (adj[node][neighbour] == 1 && !visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited( n , false);
        int count = 0;
        for( int i = 0 ; i<isConnected.size() ; i++){
            if(!visited[i]){
                bfs(isConnected , i , visited);
                count++;
            }
        }
        return count;
    }
};