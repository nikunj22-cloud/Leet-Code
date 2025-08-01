class Solution {
public:
    vector<vector<int>> directions{{1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,-1}, {-1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // If start or end is blocked
        if (grid[0][0] != 0 || grid[m-1][n-1] != 0)
            return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // mark visited with distance 1

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            int dist = grid[x][y];

            if (x == m - 1 && y == n - 1)
                return dist;

            for (auto dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    grid[nx][ny] = dist + 1;  // store distance here
                }
            }
        }
        return -1; // path not found
    }
};
