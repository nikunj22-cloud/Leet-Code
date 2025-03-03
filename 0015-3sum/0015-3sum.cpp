class Solution {
public:
 vector<vector<int>>result;
    void twoSum( vector<int>& nums , int start ,  int end  , int target){
         //target se check kro 
       
         while(start < end){
            if(nums[start]+ nums[end] > target){
                end--;
            }
            else if( nums[start] + nums[end] < target){
                start++;
            }
            else {
                //nums[start]==target mtlb hmko apni value mil gyi
                //phle check kro result m push krnwe se phle ki yeh duplicate toh ni h
                while( start < end && nums[start]==nums[start+1]) start++;
                while(start < end  && nums[end]== nums[end-1])end--;
                //duplicacy remove then push in to result
                result.push_back({ -target  , nums[start] , nums[end]});
                //ans mil jane k bad toh or b check krne pdege isliye
                start++;
                end--;
            }
         }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if( n<3){
            return {} ; //empty vector<vector
        }
        result.clear();
      //step1 sort kyoki value return krne ko voli h na ki index
      sort( nums.begin() , nums.end());
        //step2 //find n1  - sabse phle duplicate htao
        for( int start = 0 ; start<  n ; start++){
            if(  start>0 && nums[start]== nums[start-1]){
                continue;
            }
            int n1 = nums[start]; //assign krdiya
            int target = -n1; // n1+n2+n3 = target where target = 0, n2+n3 = -n1;

        
        twoSum(nums ,start+1 , n-1 , target); //step3 two sum
        }
       return result; 
    }
    
};