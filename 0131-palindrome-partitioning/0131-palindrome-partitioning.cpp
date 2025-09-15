class Solution {
public: 
       bool ispalindrom( string s){
        string s2 = s;
        reverse(s2.begin() , s2.end());
         return s == s2;
       }
     void getallparts( string s , vector<string>&partition , vector<vector<string>>&ans){
        
          if( s.length() == 0 ){
            ans.push_back(partition);
            return ;
          }
          for( int i = 0 ; i< s.length() ; i++){
             string part = s.substr( 0 , i+1);
             if(  ispalindrom(part)){
                 partition.push_back(part);
                getallparts( s.substr(i+1) , partition , ans );
                partition.pop_back();
             }
          }
     }
    vector<vector<string>> partition(string s) {
         vector<string>partition;
         vector<vector<string>>ans;
         getallparts( s , partition , ans);
         return ans;
    }
}; //yt apna clg