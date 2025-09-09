class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
          int gola_index = -1;
         for( int i = n-1 ; i> 0 ; i--){ //remeber i > 0 
            if( nums[i-1] < nums[i]){
                gola_index = i-1;
                break;
            }
         }
         int  swap_index = gola_index;
         if(  gola_index != -1){
         for( int j = n-1 ; j>= gola_index+1 ; j--){ //remember gola_index+1
               if( nums[j] > nums[gola_index]){
                swap_index = j;
                break;
               }
         }
               swap( nums[swap_index] , nums[gola_index]);
              
         }
      reverse( nums.begin()+gola_index+1 , nums.end());
    }
};