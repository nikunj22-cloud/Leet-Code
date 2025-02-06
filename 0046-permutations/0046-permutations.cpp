class Solution {
public:
int n ;
vector<vector<int>>result;
void solve( vector<int>& nums , int idx){
    n = nums.size();
    if( idx == n){
        result.push_back( nums);
    }
    for( int i = idx ; i< n ; i++){
        swap( nums[idx], nums[i]); //first swap krenge 

        solve( nums , idx+1); //then explore krenge
        swap( nums[idx] , nums[i]); //fir aage swap krenge
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        solve( nums , 0);
        return result;
    }
};