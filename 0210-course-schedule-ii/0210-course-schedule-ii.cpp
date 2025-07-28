class Solution {
public: 

     vector<int>topologicalsort( unordered_map<int , vector<int>>&adj , vector<int>&indegree ,  int n ){
        vector<int>result;
        queue<int>que;
       
        for( int i = 0 ; i<n ; i++){
              if(indegree[i] == 0){
                result.push_back(i);
                que.push(i);
              }
        }
        while( !que.empty()){
            int u = que.front();
            que.pop();
            for( auto &v : adj[u]){
                indegree[v]--;
                if( indegree[v] == 0){
                    
                    result.push_back(v);
                    
                    que.push(v);
                }
            }
        }
        if( result.size() == n)
        return result;
        
        return {};
     }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , vector<int>>adj;
        
        vector<int>indegree( numCourses , 0 );
          for( auto &vec : prerequisites){
             int a = vec[0];
             int b = vec[1];
             adj[b].push_back(a);
             indegree[a]++;
          }

          return topologicalsort( adj , indegree, numCourses);
    }
};