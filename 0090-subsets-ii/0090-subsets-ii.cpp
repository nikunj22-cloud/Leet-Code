class Solution {
public:
    void backtrack(int ind, vector<int>& nums, vector<int>& subset,vector<vector<int>> &ans){
       
        ans.push_back(subset);//Jab subset empty hai → [] add ho jaata hai
        //kyoki khali set b ans m h isliye koi condition check ni krnni h
    
        for(int i=ind; i<nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1])continue;
            subset.push_back(nums[i]); //subset nikalne ka yeh hee tarika h push kro operation perform kro pop back kro 
            backtrack(i+1,nums,subset,ans);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end()); //duplicate contain krta h isliye duplicate sort hone pr sath m aajayneg condition fast exectue hogi
        backtrack(0, nums, subset, ans);
        return ans;
    }
};