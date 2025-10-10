class Solution {
public: 
    int t[501][501];
    int m, n;

    int solve(string &s1, string &s2, int i, int j) {
        if(t[i][j] != -1)
            return t[i][j];

        if(i == m) return n - j;
        if(j == n) return m - i;

        if(s1[i] == s2[j])
            return t[i][j] = solve(s1, s2, i+1, j+1);

        int insert = 1 + solve(s1, s2, i, j+1);
        int deleteOp = 1 + solve(s1, s2, i+1, j);
        int replace = 1 + solve(s1, s2, i+1, j+1);

        return t[i][j] = min({insert, deleteOp, replace});
    }

    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        memset(t, -1, sizeof(t));
        return solve(word1, word2, 0, 0);
    }
};
