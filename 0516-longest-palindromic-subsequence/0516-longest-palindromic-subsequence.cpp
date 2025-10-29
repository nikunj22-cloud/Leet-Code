class Solution {
public: 
        int t[1001][1001];

    int solve(string &s1, string &s2, int i, int j) {
       if (i == 0 || j == 0)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        if (s1[i-1] == s2[j-1])
            return t[i][j] = 1 + solve(s1, s2, i-1, j-1);

        return t[i][j] = max(solve(s1, s2, i - 1, j), solve(s1, s2, i, j - 1));
    }
    int longestPalindromeSubseq(string s) {
          string s2 = s;
            reverse( s2.begin() , s2.end());
          int m = s.length();
          int n = s2.length();
          memset( t , -1 , sizeof(t));
          return solve( s , s2 , m ,n);
    }
};