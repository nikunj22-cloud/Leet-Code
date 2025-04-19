class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int sum = 0;
        int count = 0;
         mp[0] = 1; //map m 0 sum mana shuru m or uski freq 1 krdi phle hee
        for( int i = 0 ; i<nums.size() ; i++){
              sum += nums[i];
               int rem = sum-k;
        
        if( mp.find(rem) != mp.end()){
                  count +=  mp[rem];
        }
        mp[sum]++;
        }

        return count;
    
    }
};