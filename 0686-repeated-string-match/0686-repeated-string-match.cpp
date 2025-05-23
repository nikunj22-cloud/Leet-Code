class Solution {
public:
    int repeatedStringMatch(string a, string b) {
       string repeated = a;
       int count = 1;
       while( repeated.size() <b.size()){
        repeated += a;
        count++;
       }      
       if(repeated.find(b) != string::npos)return count;
       //one more add
       repeated += a; //if abc , cba over lap
       count++;

       //final return 
       return (repeated.find(b) != string::npos)? count : -1;
    }
};


// Best Case (b is already in a) → O(N)
// Worst Case (needs full repetitions) → O(M * N), where M = b.size() and N = a.size()
// Space Complexity: O(M), since repeated grows to store repeated a.