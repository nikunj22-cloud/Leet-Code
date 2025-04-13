class Solution {
public: 
    void getsubset( vector<int>& nums , vector<vector<int>>& getans , int i , vector<int>& ans){
        if( i == nums.size()){
            getans.push_back( ans);
            return ;
        }
        ans.push_back( nums[i]);
        getsubset(nums , getans , i+1 , ans);
        ans.pop_back();

        int idx = i+1;
        while( idx < nums.size() && nums[idx] == nums[idx-1]) idx++;

        getsubset( nums , getans , idx , ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>getans;
         vector<int>ans;
          getsubset( nums , getans , 0 , ans);

          return getans ;
    }
};