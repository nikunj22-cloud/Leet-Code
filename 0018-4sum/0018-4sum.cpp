class Solution {
public: 
vector<vector<int>>ans;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n = nums.size();
         sort( nums.begin() , nums.end());
         for(  int first = 0 ; first< n-3 ; first++){
            if( first > 0 && nums[first]== nums[first-1])continue; //because of unique quadrent
            for(int second = first+1 ; second< n-2 ; second++){
                if( second > first+1  && nums[second] == nums[second-1])continue;
                 int third = second+1;
                 int forth = n-1;
                 while( third< forth){ //sum is defined in to the loop
                     long long sum = (long long)nums[first] + (long long)nums[second] + (long long)nums[third] + (long long )nums[forth];
                    if( sum > target){
                        forth--;
                    }
                    else if ( sum < target){
                        third++;
                    }
                    else{
                        //target mil gya 
                        ans.push_back({nums[first] , nums[second] , nums[third] , nums[forth]});
                        third++;
                        forth--;
                        
                         while( third< forth && nums[third]== nums[third-1])third++; //remember in the else 
                    }
                   
                    
                 }
            }
         }
         return ans;
    }
};