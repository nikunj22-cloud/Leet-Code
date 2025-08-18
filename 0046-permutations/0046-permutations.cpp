class Solution {
public:
   void perm( vector<int>&per , int idx , vector<vector<int>>&ans){
    if( idx == per.size()){
        ans.push_back(per);
        return;
    }
    for( int i = idx ; i< per.size() ; i++){
          swap( per[idx] , per[i]);
        perm(per , idx+1 , ans);
        swap(per[idx] , per[i]);
        //backtrack
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        perm(nums , 0 , ans);
        return ans;

    }
};