class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1 = INT_MIN;
        int maj2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        for( int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == maj1){
                count1++;
            }
            else if( nums[i] == maj2){
                count2++;
            }
            else if(  count1 == 0){
                maj1 = nums[i];
                count1 = 1;
            }
            else if( count2 == 0 ){
                maj2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>ans;
        count1 = count2 = 0;
        int n = nums.size();
     for( int i = 0 ; i <nums.size() ; i++){
        if( nums[i] == maj1)count1++;
        if(  nums[i] == maj2) count2++;
     }
          if( count1 > n/3) ans.push_back( maj1);
            if( count2 > n/3) ans.push_back( maj2);
        
        return ans;  
     }
};