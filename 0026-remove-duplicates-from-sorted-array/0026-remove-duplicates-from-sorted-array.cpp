class Solution {
public:
  //phle i ko aage bdhayenge kyoki i jha pr hoga wha b unique elemenet store hoga isliye agr whi pr dusra 
            //unique element store kr diya toh glt hoga
            //agr num[i]!= num[j] agr esa h hee nhi toh j ko aage bdhate rhenge jb tk unique element na mil jaye
            //i+1 element return krenge kyoki i zero base indexing pr h toh total agr ans m 5 element hoge toh 4 return krega isliye
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();

        while(j< n){
            if(nums[i]!= nums[j]){
                i++;
            nums[i] = nums[j];
            }
            j++;
        }
        
        return i+1;
    }
};