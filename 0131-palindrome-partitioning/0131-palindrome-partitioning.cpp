class Solution {
public:
  bool palindrom( string s){
         int i = 0;
         int j = s.length()-1;
         while( i< j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
         }
         return true;
      }
    void getallparts( vector<vector<string>>&ans , string s , vector<string>&part){
         if(s.size() == 0){
            ans.push_back(part);
            return ;
         }
        for( int i = 0 ; i<s.length() ; i++){
              string parti = s.substr( 0 , i+1);
              if(palindrom(parti)){
                part.push_back(parti);
                getallparts(ans , s.substr(i+1) , part);
                part.pop_back();
              }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>part;
         getallparts(ans , s , part);
         return ans;
        
    }
};