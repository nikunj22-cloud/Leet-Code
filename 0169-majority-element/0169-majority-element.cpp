class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int majority = 0 ;
        for( int i = 0 ; i<nums.size() ; i++){
           if(count==0) //sabse phle count 0 h toh majority assign krdo because You may assume that the majority element always exists in the array.
            majority = nums[i];
            count++;
        
           if(nums[i]== majority){
            count++; //ab agr traverse krte krte ek or nums[i] mila joh majority k jitna h toh count ++ krdo
           }
           else{
            count--; //nhi toh count--  mtlb woh element ek bar hee aya h toh kya fayda usko majority manne ka agr ek bar aaya hoga toh zero hojayega - hoker then count ek new majority assign krlega
           }
        }
        return majority;
    }
};