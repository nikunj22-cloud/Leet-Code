class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int maxpro = nums[0];
        int minpro = nums[0];
    
        for( int i = 1 ; i<nums.size() ; i++){
            int curr = nums[i];
             
            int tempmax = max({curr*minpro , maxpro*curr , curr});
             int tempmin = min( {maxpro*curr , minpro*curr , curr});
              maxpro = tempmax;
              minpro = tempmin; //current bar bar maxpro ko change krrha h isliye uper k multiply se maxpro alg ho jayega isliye neeche varaible liye h
            result = max( maxpro , result);
        }
      return result;  
    }
};