class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //sort the string
        sort(strs.begin() , strs.end());
        
        //compare first and last of the string
        string first = strs[0]; //first string
        string last = strs[strs.size() -1]; //second string
        string result = ""; //result joh string store krega
        for( int i = 0 ; i< first.size() ; i++){ //loop chlaya or compare krra first string ko last string se
            if(first[i] != last[i]) break; //agr element same nhi h toh break kr diya
            result += first[i]; //nhi toh result m add krdiya koi si bkrlo prefix  hee add hogi
        }
        return result;
    }
};