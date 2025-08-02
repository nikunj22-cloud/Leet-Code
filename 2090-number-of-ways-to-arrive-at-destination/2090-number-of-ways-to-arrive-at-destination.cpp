class Solution {
public: 
    typedef pair<long long , int >p;
     const int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
       unordered_map<int, vector<pair<int , int >>>adj;
       priority_queue< p , vector<p> , greater<p>>pq;
       vector<long long >result(n , LLONG_MAX);
       vector<int>pathcount( n , 0);
       for( auto &vec : roads){
        int u = vec[0];
        int v = vec[1];
        int time = vec[2];
        adj[u].push_back({v , time});
        adj[v].push_back({u , time});
       }   
       result[0] = 0;
       pq.push({0 , 0});
       pathcount[0] = 1;
      while( !pq.empty()){
        long long  d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for( auto &vec : adj[node]){
            int adjnode = vec.first;
            int dist = vec.second;
            if( dist + d < result[adjnode]){
                result[adjnode] = dist+d;
                pq.push({ d+dist , adjnode});
                pathcount[adjnode] = pathcount[node];
            }
            else if( dist+d == result[adjnode]){
                pathcount[adjnode] = (pathcount[adjnode] + pathcount[node])%M;
            }
        }
      }
      return pathcount[n-1] ;
    }
};