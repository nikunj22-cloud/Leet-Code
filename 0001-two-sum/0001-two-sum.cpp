class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int >mp;
        vector<int>ans;
        for( int i = 0 ; i<nums.size(); i++){
             int remain = target - nums[i];
            if( mp.find( remain) != mp.end()){
                 return {mp[remain] , i};
            }
            mp[nums[i]] = i;
        }
        return {} ;
    }
};