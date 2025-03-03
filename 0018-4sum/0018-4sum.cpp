class Solution {
public: 
vector<vector<int>>ans;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort( nums.begin() , nums.end());
        int n = nums.size();

        for( int first = 0 ; first < nums.size() ; first++){
            if( first > 0 && nums[first]==nums[first+1])continue;
            for( int second = first+1 ; second< nums.size(); ){
                 int third = second+1;
                 int forth = n-1;
                while( third< forth){
                 long long sum  =  (long long)nums[first]+ (long long )nums[second] + (long long) nums[third] + (long long) nums[forth];
                 
                 if( sum > target){
                    forth--;
                 }
                 else if(sum < target){
                    third++;
                 }
                 else{
                    ans.push_back({ nums[first], nums[second] , nums[third] , nums[forth]});
                    third++;
                    forth--;
                    while( third < n && nums[third] == nums[third-1])third++;

                 }
                   
                 }
                 second++;
                 while( second < n && nums[second]==nums[second-1]) second++;  
                
            }
        }
  return ans;
    }
};