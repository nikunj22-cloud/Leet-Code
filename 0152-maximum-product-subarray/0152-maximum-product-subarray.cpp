class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro = nums[0];
        int pro = 1;
        for( int i = 0 ; i<nums.size() ; i++){
            pro *=  nums[i];
            maxpro = max( maxpro , pro);

            
        if( pro < 0)
          pro = 1;
        }

      return maxpro ;
    }
};