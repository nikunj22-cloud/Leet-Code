class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;//is for unique element
        int j = 1; //is for traverse and find unique or duplicate
        int n = nums.size();
        while( j < n){
              if( nums[i]  != nums[j]){
                i++;//jgh bnayega i k liye 
                nums[i] = nums[j]; // bn jane k bad i m j ki value ko daldega
              }
              j++;
        }
        return i+1; //for size becuase i toh index dikha rha h 
    }
};