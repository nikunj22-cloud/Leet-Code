class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;

        // Step 1: Push all rotten oranges initially
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int maxtime = 0;
        // Step 2: BFS
        while (!q.empty()) {
            int f = q.front().first.first;
            int s = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxtime = max(maxtime, time);

            // left
            if (f < n && s - 1 >= 0 && grid[f][s - 1] == 1) {
                q.push({{f, s - 1}, time + 1});
                grid[f][s - 1] = 2; // mark rotten
            }
            // right
            if (f < n && s + 1 < m && grid[f][s + 1] == 1) {
                q.push({{f, s + 1}, time + 1});
                grid[f][s + 1] = 2;
            }
            // up
            if (f - 1 >= 0 && s < m && grid[f - 1][s] == 1) {
                q.push({{f - 1, s}, time + 1});
                grid[f - 1][s] = 2;
            }
            // down
            if (f + 1 < n && s < m && grid[f + 1][s] == 1) {
                q.push({{f + 1, s}, time + 1});
                grid[f + 1][s] = 2;
            }
        }

        // Step 3: Check if any fresh orange is left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return maxtime;
    }
};
