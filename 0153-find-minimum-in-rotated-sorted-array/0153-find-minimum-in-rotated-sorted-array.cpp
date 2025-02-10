class Solution {
public:
    int findMin(vector<int>& nums) {
          int l = 0;
           int n = nums.size();
          int r = n-1;
          while( l < r){
            int mid = l+(r-l)/2;

            if(nums[mid] > nums[r]){ //gadbad h kyoki array sorted order m h toh minimum mera element right side main rhega
                l = mid+1;
            }
            else {
                r = mid ; //yeh b min element ho skta h
            }
          }
          return nums[r];
    }
};