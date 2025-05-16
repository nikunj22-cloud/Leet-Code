class Solution {
public:
   typedef pair<int , int>p;
   vector<vector<int>>direction{{-1,0},{1,0},{0 , -1},{0,1}}; // upr neeche aage peeche
    int orangesRotting(vector<vector<int>>& grid) {
        
         int freshOrange = 0;
         int minute = 0;
         int rottanOrange = 0;
         int m = grid.size();
         int n = grid[0].size();
        queue<p>q;
        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j< n ; j++){
                if(grid[i][j] == 2){
                  q.push({i , j});
                }
                if( grid[i][j]==1){
                    freshOrange++;
                }
            }
        }
       if(freshOrange == 0){
        return 0;
       }
        while( !q.empty()){
          int N = q.size();
          while(N--){
            p curr = q.front() ;
            q.pop();
            int i = curr.first;
            int j = curr.second;
            
            for( vector<int>&dir : direction){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j]==1){
                    grid[new_i][new_j] = 2;
                    q.push( {new_i , new_j});
                    freshOrange--;
                }
            }
          }
          minute++;
        }
        return freshOrange == 0 ? (minute-1) : -1;
      

    }
};