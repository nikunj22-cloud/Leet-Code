class Solution {
public: 
 //step 1 version1 ko token m todo '
 //step2 token ko string se integer m convert kro
 // then compare kro
        vector<string>gettoken( string version){
            stringstream ss( version);
            string token = "";
            vector<string>tokens;
            

            while( getline( ss , token , '.')){ //ss wale fucntion  k nikle token ko string token m dal diya token ss wale function . k basic pr nikale gye h
                tokens.push_back( token);
            }
            return tokens;            
       }
    int compareVersion(string version1, string version2) {
        vector<string>v1 = gettoken( version1);
        vector<string>v2 = gettoken( version2);

        int m = v1.size();
        int n = v2.size();
        int i  = 0 ; // must be initilize with 0
          while( i < m || i < n ){
              int a =  i < m ?  stoi(v1[i]) : 0 ;
              int b  = i < n ? stoi(v2[i]) : 0 ;

              if( a < b)
                return -1;
              else if( b > a)
                return 1;
              
              else
                i++;
          }
          return 0;
    }
};