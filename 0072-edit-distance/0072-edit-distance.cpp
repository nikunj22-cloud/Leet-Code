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
//Case 1: i == m
// if(i == m) return n - j;


// We have reached the end of word1.

// word1 has no characters left, but word2 may still have n - j characters remaining.

// To convert word1 to word2, we need to insert all remaining characters of word2.

// So, number of operations = n - j

// ✅ Example:

// word1 = "abc", word2 = "abcd", i = 3, j = 3


// i == m = 3, j = 3

// Remaining characters in word2 = n - j = 4 - 3 = 1 → we need 1 insert ('d')

// Case 2: j == n
// if(j == n) return m - i;


// We have reached the end of word2.

// word1 may still have m - i characters left.

// To convert word1 to word2, we need to delete all remaining characters of word1.

// So, number of operations = m - i

// ✅ Example:

// word1 = "abcd", word2 = "abc", i = 3, j = 3


// j == n = 3, remaining characters in word1 = m - i = 4 - 3 = 1 → we need 1 delete ('d')
