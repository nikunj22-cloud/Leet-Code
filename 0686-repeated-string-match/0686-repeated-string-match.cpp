class Solution {
public:
    int repeatedStringMatch(string a, string b) {
      string repeated = a;
        int count = 1;

        // Keep repeating until the length is at least b's size
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check if b is a substring after minimum required repetitions
        if (repeated.find(b) != string::npos) return count;

        // One extra repetition might be required
        repeated += a;
        count++;

        // Final check after extra repetition
        return (repeated.find(b) != string::npos) ? count : -1;   
    }
};