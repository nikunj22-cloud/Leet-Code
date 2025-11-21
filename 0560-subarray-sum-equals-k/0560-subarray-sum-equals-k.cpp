class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        //sum or map m freq ko rkhne k liye
        int count = 0;
        int sum = 0;
          mp[0] = 1; //map m 0 sum ki 1 freq count krdi
          
        for( int i = 0 ; i<nums.size() ; i++){
            sum += nums[i];
            int rem = sum - k; //remember sum-k

            if( mp.find(rem) != mp.end()) {
                count += mp[rem];
            }
            mp[sum]++;
        }
     return count;
    }
};