class Solution {
public:
     vector<vector<int>>result; // jisme subset return honge
     void SubSet(vector<int>& nums , vector<int>& temp , int i ){
        if( i>= nums.size()){  //if condition isliye lgayi h kyoki agr loop lga diya toh push or pop sab loop k khtm hone k bad chlenge
            return result.push_back(temp); //jb i out of reach ho gya mtlb sub set bn chuke h
        }
        temp.push_back( nums[i]); //phle liya
        SubSet(nums , temp , i+1); //then explore kiya 
        temp.pop_back();//usi trh phle nhi liya 
        SubSet(nums , temp , i+1); //then  explore kiya

     }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp; //subset koo store krne k liye temp m
          SubSet( nums , temp , 0);

          return result;
    }
};