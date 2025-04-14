class Solution {
public:
       vector<vector<int>>result;
      void Pick( vector<int>& candidates , int target , vector<int>& ds , int i ){
        if( i == candidates.size()){
            if( target == 0){
                result.push_back(ds);
            }
            return ;
        }
          if( candidates[i] <= target){
        ds.push_back(candidates[i]);
        Pick(candidates , target - candidates[i]  , ds , i);
        ds.pop_back();
          }
          Pick(candidates , target , ds , i+1 );
      }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        Pick( candidates , target , ds , 0);
        return result;
        
    }
};