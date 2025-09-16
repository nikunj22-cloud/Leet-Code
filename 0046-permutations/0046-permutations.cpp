class Solution {
public:
      void perm( vector<int>&per , int space  ,  vector<vector<int>>&ans){
        if( space == per.size()){
            ans.push_back(per);
            return;
        }
         int n = per.size();
        for( int i = space ; i< n ; i++){
            swap( per[space] , per[i]);
            perm( per , space+1 , ans);
            swap(per[i] , per[space]);//keeping original backtrack step
        }
      }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        perm( nums , 0 , ans);
        return ans;
    }
};