class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int currentsum = 0 ;
        for( int i = 0 ; i< nums.size() ; i++){
              currentsum += nums[i];
              if( currentsum >  sum){
                sum = currentsum;
              }
              if( currentsum < 0){
                currentsum = 0;
              }
        }
        return sum ;
    }
};