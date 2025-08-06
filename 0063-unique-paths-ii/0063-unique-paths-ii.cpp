class Solution {
public: 
    int t[101][101];

    int unique(int m, int n, int i, int j, vector<vector<int>>& ob) {
        if (i >= m || j >= n) return 0; // Out of bounds
        if (ob[i][j] == 1) return 0;    // Obstacle
        if (i == m-1 && j == n-1) return 1; // Destination
        if (t[i][j] != -1) return t[i][j];  // Memoized result

        int down = unique(m, n, i+1, j, ob);   // Move down
        int right = unique(m, n, i, j+1, ob);  // Move right

        return t[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(t, -1, sizeof(t));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) return 0; // Start blocked
        return unique(m, n, 0, 0, obstacleGrid);
    }
};
