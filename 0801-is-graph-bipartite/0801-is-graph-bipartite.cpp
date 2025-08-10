class Solution {
public: 
     bool bfs( vector<vector<int>>& graph , int currcolor , int node , vector<int>& color){
        queue<int>que;
        que.push(node);
        color[node] = currcolor;
        while( !que.empty()){
            int u = que.front();
            que.pop();
            for( int v : graph[u]){
                if( color[v] == color[u]){
                    return false;
                }
                if( color[v] == -1){
                    color[v] = 1- color[u];
                    que.push(v);
                }
            }
        }
        return true;
     }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
         vector<int>color( v , -1);
         for( int i = 0 ; i< v ; i++){
            if(color[i] == -1){
               if (!bfs(graph, 0, i, color)) {
                    return false;
                }
            }
         }
         return true;
    }
};