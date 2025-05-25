class Solution {
public:
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Return true if pat is a substring of txt using KMP
    bool containsPattern(string& txt, string& pat) {
        int N = txt.length();
        int M = pat.length();
        vector<int> lps(M, 0);
        computeLPS(pat, lps);

        int i = 0, j = 0;
        while (i < N) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == M) return true;

            else if (i < N && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        if (a == b) return 1;

        string temp = a;
        int repeat = 1;

        while (temp.length() < b.length()) {
            temp += a;
            repeat++;
        }

        // Check if b is in current repeated string
        if (containsPattern(temp, b)) return repeat;

        // One more repetition might help in overlap case
        temp += a;
        if (containsPattern(temp, b)) return repeat + 1;

        return -1;
    }
};
