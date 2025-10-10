class Solution {
public:  
 int  t[2501][2501];
    int solve( vector<int>&nums, int prev_ind , int curr_ind){
        int n = nums.size();
         if(curr_ind == n){
           return 0;
         }
           if( prev_ind != -1 && t[prev_ind][curr_ind] != -1){
            return t[prev_ind][curr_ind];
           }
            int taken = 0;
            int notaken = 0;
           if( prev_ind == -1 || nums[prev_ind] < nums[curr_ind]){
                taken = 1+ solve( nums , curr_ind , curr_ind+1);
           }
           notaken =  solve( nums , prev_ind , curr_ind+1);
           if( prev_ind != -1)
            t[prev_ind][curr_ind] = max( taken , notaken);
            return max( taken , notaken);
           

    }
    int lengthOfLIS(vector<int>& nums) {
          memset( t , -1 , sizeof(t));
          int n = nums.size();
          return solve( nums, -1 , 0);
    }
};