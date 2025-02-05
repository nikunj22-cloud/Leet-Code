class Solution {
public:
void FindCombination( vector<int>& candidates , int target , int i , vector<int>& ds , vector<vector<int>>& result){
    if(i == candidates.size()){ //agr i size tk phuch gya or target b 0 ho gya toh mtlb isko result m push krdo yhi combination h
        if(target == 0){
            result.push_back(ds);
        }
        return;
    }
    if(candidates[i]<=target){ //agr nhi h check kro condition se
        ds.push_back(candidates[i]); //pick kiya 
        FindCombination( candidates , target - candidates[i] , i , ds , result); //pick krke aage recursion chalaya
        ds.pop_back(); //pop kiya backtracking k time nnhi toh yeh target m jud jayega
    }
    FindCombination(candidates , target , i+1 , ds , result); //dobara non pick wala function chalaya
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds; //pick or non pick ko store krne k liye
        vector<vector<int>>result; //final answer ko store krke combination return krne k liye
         FindCombination( candidates , target , 0 , ds ,result);
         return result;
    }
}; //time complexity is 2ki power t * k , and sc is X*K k is total length of result , and x is total combinations