class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
           int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));  // -1 = not visited
        queue<pair<int, int>> q;

        // Step 1: sabhi 0s ko queue mein daal do
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int , int>>dir = {{0 , 1},{1 ,0},{0,-1},{-1,0}};

        while(!q.empty()){
           auto[x ,y] = q.front();
            q.pop();
            for( auto [dx , dy] : dir ){
                int nx = dx+x;
                int ny = dy+y;

                 // valid cell and not visited yet
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    }
};