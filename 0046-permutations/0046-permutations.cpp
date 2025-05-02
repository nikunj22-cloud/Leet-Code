class Solution {
public:
vector<vector<int>>result;
int n;
 void SwapAns( vector<int>& nums , int idx){
    n = nums.size();
    if( idx == nums.size()){
        result.push_back(nums);
    }
    for( int i = idx ; i< n ; i++){
        swap(nums[idx] , nums[i] );
        SwapAns( nums , idx+1);
        swap( nums[idx] , nums[i]);
    }
 }
    vector<vector<int>> permute(vector<int>& nums) {
        SwapAns( nums , 0);
        return result;
    }
};