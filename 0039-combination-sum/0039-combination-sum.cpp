class Solution {
public:
    void helper(int i,int target,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==nums.size())return;
        if(target<nums[i])return;
        temp.push_back(nums[i]);
        helper(i,target-nums[i],nums,temp,ans);
        temp.pop_back();
        helper(i+1,target,nums,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());//The test cases are generated such that the number of unique isliye sort kiya h
        helper(0,target,candidates,temp,ans);
        return ans;
    }
};

          // jha return m vector of vector diya h wha aankh bnd krke backtracking lgegi chahe subset sum , ya subset diya ho but agr vector hota h toh wha choice h wha agr sum nikalna h toh back tracking ni chlegi