class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n = nums.size();
       int gola_index = -1;
       for( int i = n-1 ; i> 0 ; i--){ // remember i > 0
        if( nums[i-1] < nums[i]){
             gola_index = i-1;
            break;
        }
       } 
        int swapindex = gola_index;
        if( gola_index != -1){
            for( int j = n-1 ; j>= gola_index+1 ; j--){
               if( nums[gola_index]  < nums[j]){
                swapindex = j;
                break;
               }
            }
            swap( nums[gola_index] , nums[swapindex]);
        }
        reverse( nums.begin()+ gola_index+1 , nums.end() );
    }
};