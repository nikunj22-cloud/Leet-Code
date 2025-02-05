class Solution {
public: 
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size(); 
       int i =0 ;
       int j  = 1 ;
      while( j< n){
      
        if( nums[i] != nums[j]){
            i++; //phle i ko aage bdhayenge kyoki i jha pr hoga wha b unique elemenet store hoga isliye agr whi pr dusra 
            //unique element store kr diya toh glt hoga
            nums[i] =  nums[j];
            
        }
        j++; //agr num[i]!= num[j] agr esa h hee nhi toh j ko aage bdhate rhenge jb tk unique element na mil jaye
       }
       return i+1;
    }
};