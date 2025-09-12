class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        sort( nums.begin() , nums.end());
         int n = nums.size();
        for( int i = 0 ; i<nums.size() ;i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;
            for( int j = i+1 ; j < nums.size() ; j++){
                if( j > i+1 && nums[j] == nums[j-1])continue;
                int l = j+1 ; 
                int k = n-1;
                while( l < k){
                     long long  sum = (long long)nums[i]+ nums[j]+nums[l] + nums[k];
                    if( sum == target){
                        result.push_back({nums[i] , nums[j] ,nums[l] , nums[k]});
                    
                    k--;
                    l++;
                    while( l < k && nums[l] == nums[l-1]) l++;//while loop h isliye ++ hoga agr if ki condition hoti toh continue aata duplicate k liye 
                    while( l < k && nums[k] == nums[k+1]) k--;
                    }
                    else if( sum < target){
                        l++;
                    }
                    else{
                        k--;
                    }
                }
                
            }
        }
        return result;
    }
};