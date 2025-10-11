class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int slow = nums[0]; 
         int fast = nums[0];
         slow = nums[slow];//agr hmko ek ek krkr array m traverse krwana h toh nums[slow] isliye liya h
         fast = nums[nums[fast]];//agr nhi update kia toh phli iteration pr hee loop end ho jayega
         while( slow != fast){
            //for detect a cycle
            slow = nums[slow];
            fast = nums[nums[fast]];
         }
         //detect a cycle point
         slow = nums[0];
         while( slow != fast){
            slow = nums[slow];
            fast  = nums[fast];//remember second time fast 1 point hee chlega
         } 

         return slow;
    }
};