class Solution {
public:
  bool CheckBipertite(vector<vector<int>>& graph , int curr , vector<int>&color , int currcolor ){
    color[curr] = currcolor ;  //phle to color krdo then condition check krdo
     
     for( int &v : graph[curr]){
        if( color[curr]==color[v]){ //first condition ki curr color or color[v] traverse krne wala color same h mtlb adj node same color k hoge joh kbhi ni ho skta
            return false;
        }
         if( color[v] == -1){
          int  colorofV = 1- currcolor;
           //mtlb color khali h isliye color pta kro kon sa bhra jayega uske liye trick h

         
        if( CheckBipertite(graph , v , color , colorofV)==false)
            return false;
        } 
     
     }
        return true;

  }
    bool isBipartite(vector<vector<int>>& graph) {
         int V = graph.size();
         vector<int>color(V , -1);

         for( int i =0 ; i<V ; i++){
            if(color[i]==-1){
                if(CheckBipertite(graph , i , color , 1)== false)
                return false;
            }
         }
        return true;
         
    }
};