class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>setRows;
        set<int>setCols;
        int m = matrix.size();
        int n = matrix[0].size();
        for( int i = 0 ; i< m ; i++){
            for( int j = 0 ; j<n ; j++){
                 if(matrix[i][j] == 0){
                setRows.insert(i);
                setCols.insert(j);
            }
            }
        }
        for( int Rows : setRows){
         for( int i = 0  ; i< n ; i++){
             matrix[Rows][i] = 0;
         }
        }
        for( int Col : setCols){
              for( int j = 0 ; j<m ; j++){
                matrix[j][Col] = 0;
              }
        }
    }
};