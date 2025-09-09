class Solution {
public:
    void sortColors(vector<int>& nums) {
         int i = 0;
         int j = 0;
         int n = nums.size();
         int k = n-1;
         while( j<= k){
            if( nums[j]==1){
                j++;
            }
            else if( nums[j]==2){
                swap( nums[j] , nums[k]);
               k--;
            }
            else{
                swap(nums[j] , nums[i]);
                i++; //because dono ko swap kiya h then dono start b ek jgh se hue h 
                j++;
            }
         }
    }
};