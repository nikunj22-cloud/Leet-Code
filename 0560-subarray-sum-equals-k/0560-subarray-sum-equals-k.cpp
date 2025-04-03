class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int n = nums.size();
         int count = 0;
           //step 1 find prefix sum
           vector<int>prefixSum( n , 0);
           prefixSum[0]  = nums[0];
         for( int i = 1 ; i< n ; i++){
          prefixSum[i] = prefixSum[i-1] + nums[i];
         }
         unordered_map<int , int>mp ; //freq or sum ko store krne k liye

         for( int j = 0 ; j< n ; j++){
            if(prefixSum[j] == k) count++;
             int val = prefixSum[j] - k ;
             if( mp.find(val) != mp.end()){
                count += mp[val];
             }
             if( mp.find(prefixSum[j]) == mp.end()){
                mp[prefixSum[j]] = 0;
             }
             mp[prefixSum[j]]++;
         }
         return count;
    }
};