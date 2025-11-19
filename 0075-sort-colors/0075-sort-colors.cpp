class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int k = n-1;
        while(  j <= k){ //remember
            if( nums[j] == 1){
                j++;
            }
             else if( nums[j] == 0){
                swap( nums[j] , nums[i]);
                j++;
                i++;
            }
            else{
                swap( nums[j] , nums[k]);//remember
                k--; // i toh shurur m hee rhega or k last m hee rhega so isliye usko ++ or -- krrhe h  
            }

        }
    }
};