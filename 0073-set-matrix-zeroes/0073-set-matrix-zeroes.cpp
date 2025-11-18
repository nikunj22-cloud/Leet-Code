class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       set<int>setRows;
       set<int>setCols;
        int m = matrix.size();
        int n = matrix[0].size();
       for( int i = 0 ; i< m ; i++ ){
        for( int j = 0 ; j< n ; j++){
            if( matrix[i][j] == 0){
                setRows.insert(i);
                setCols.insert(j);
            }
        }
       }   
        for( int Rows : setRows){
       for( int i = 0 ; i< n ; i++){
            matrix[Rows][i] = 0;
       }
    }
    for( int Cols : setCols){
        for( int i = 0 ; i < m ; i++){
            matrix[i][Cols] = 0;
        }
    }
    }
}; 


//Ye code LeetCode ka “Set Matrix Zeroes” problem solve kar raha hai: jaha pe kisi cell me 0 ho, uski poori row aur column ko 0 bana dena hai.

// Dry run ek example ke saath karte hain.

// Le matrix lete hain:

// matrix
// =
// [
// 1
// 1
// 1
// 1
// 0
// 1
// 1
// 1
// 1
// ]
// matrix= 
  
// 1
// 1
// 1
  
// 1
// 0
// 1
  
// 1
// 1
// 1
  
 
// Step 1: Variables aur sets
// cpp
// set<int> setRows;
// set<int> setCols;
// int m = matrix.size();    // m = 3 (rows)
// int n = matrix[0].size(); // n = 3 (cols)
// setRows me un rows ke index jayenge jahan 0 milta hai.

// setCols me un columns ke index jayenge jahan 0 milta hai.

// Step 2: Pehla nested loop – 0 dhundhna
// cpp
// for (int i = 0; i < m; i++) {
//     for (int j = 0; j < n; j++) {
//         if (matrix[i][j] == 0) {
//             setRows.insert(i);
//             setCols.insert(j);
//         }
//     }
// }
// Ab iterations dekhte hain:

// i = 0:

// j = 0: matrix[0][0] = 1 → kuch nahi

// j = 1: matrix[0][1] = 1 → kuch nahi

// j = 2: matrix[0][2] = 1 → kuch nahi

// Abhi tak:

// setRows = {}

// setCols = {}

// i = 1:

// j = 0: matrix[1][0] = 1 → kuch nahi

// j = 1: matrix[1][1] = 0 → condition true

// setRows.insert(1);

// setCols.insert(1);

// j = 2: matrix[1][2] = 1 → kuch nahi

// Abhi tak:

// setRows = {1}

// setCols = {1}

// i = 2:

// j = 0: matrix[2][0] = 1 → kuch nahi

// j = 1: matrix[2][1] = 1 → kuch nahi

// j = 2: matrix[2][2] = 1 → kuch nahi

// Final after first loop:

// setRows = {1}

// setCols = {1}

// Matlab row 1 aur column 1 ko poora 0 karna hai.

// Step 3: Rows ko 0 karna
// cpp
// for (int Rows : setRows) {
//     for (int i = 0; i < n; i++) {
//         matrix[Rows][i] = 0;
//     }
// }
// setRows me sirf 1 hai, to loop me:

// Rows = 1

// Inner loop: i = 0 to 2:

// i = 0: matrix[1][0] = 0

// i = 1: matrix[1][1] = 0 (pehle se 0 hai)

// i = 2: matrix[1][2] = 0

// Ab matrix:

// [
// 1
// 1
// 1
// 0
// 0
// 0
// 1
// 1
// 1
// ]
  
// 1
// 0
// 1
  
// 1
// 0
// 1
  
// 1
// 0
// 1
  
 
// Step 4: Columns ko 0 karna
// cpp
// for (int Col : setCols) {
//     for (int j = 0; j < m; j++) {
//         matrix[j][Col] = 0;
//     }
// }
// setCols me sirf 1 hai, to:

// Col = 1

// Inner loop: j = 0 to 2:

// j = 0: matrix[0][1] = 0

// j = 1: matrix[1][1] = 0 (already 0)

// j = 2: matrix[2][1] = 0

// Final matrix:

// [
// 1
// 0
// 1
// 0
// 0
// 0
// 1
// 0
// 1
// ]
  
// 1
// 0
// 1
  
// 0
// 0
// 0
  
// 1
// 0
// 1
  
 
// Ye hi expected output hai.