class Solution {
public:
    void helper(int i,int target,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==nums.size())return;
        if(target<nums[i])return;
        if(target < 0) return;
        temp.push_back(nums[i]);
        helper(i,target-nums[i],nums,temp,ans);
        temp.pop_back();
        helper(i+1,target,nums,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());//iska matlab: agar current element nums[i] hi target se bada hai, to aage ke sare elements (jo uske baad aayenge aur sort ki wajah se aur bhi bade honge) use karke sum banana impossible hai.
        helper(0,target,candidates,temp,ans);
        return ans;
    }
};

          // jha return m vector of vector diya h wha aankh bnd krke backtracking lgegi chahe subset sum , ya subset diya ho but agr vector hota h toh wha choice h wha agr sum nikalna h toh back tracking ni chlegi
          //ek or condition jha for loop ka use nhi horha h kyoki unlimited number ko time choose krne ko bola h ni toh subset 2 , or combination sum 2  m ek bar ka choose krne ka chance h thatswhy wha for loop ka use hoga 
          //rhi bat for loop subset1 m kyo use ni hua kyoki wha pr vector of vector ka seen nni h or ek bat wha pr direct sum manga h duplicate or target ka b koi seen ni h isliye 