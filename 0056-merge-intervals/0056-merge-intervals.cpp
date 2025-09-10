class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<vector<int>>ans;
        sort(inter.begin() , inter.end());
        for( int i = 0 ; i<inter.size() ; i++){
            if( ans.empty() || inter[i][0] > ans.back()[1]){
                ans.push_back( inter[i]);
            }
            else{
                ans.back()[1] = max( inter[i][1] , ans.back()[1]);
            }
        }
        return ans;
    }
};
//Iteration 1: i = 0 → inter[0] = [1,3]

// ans is empty → push [1,3]

// ans = [[1,3]]

// Iteration 2: i = 1 → inter[1] = [2,6]

// Check: inter[1][0] = 2 > ans.back()[1] = 3? ❌ (2 ≤ 3) → overlapping

// Merge: ans.back()[1] = max(6, 3) = 6