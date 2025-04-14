class Solution {
public:
     void solve( vector<int>&candidates , vector<vector<int>>&result , int target , int idx , vector<int>&comb){
        if( target == 0){
            result.push_back(comb);
            return;
        }
        if( idx == candidates.size()){
            return;
        }
          if( target < 0){
            return;
          }
        for( int i = idx ; i< candidates.size() ; i++){
            if(  i > idx && candidates[i] == candidates[i-1]){
              continue;
            }
            comb.push_back(candidates[i]);
            solve( candidates , result , target-candidates[i] , i+1, comb);
            comb.pop_back();
        }
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort( candidates.begin() , candidates.end());
         vector<int>comb;
         vector<vector<int>>result;
         solve( candidates , result , target  , 0 , comb);

         return result;
    }
};