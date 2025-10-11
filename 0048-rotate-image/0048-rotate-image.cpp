class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();

       for( int i = 0 ; i<m ; i++){
        for(int j = i ; j< n; j++){
            swap( matrix[i][j] , matrix[j][i]);
        }
       }
       for( int i = 0 ; i< m ; i++){
        reverse( matrix[i].begin() , matrix[i].end());
       }
    }
};
//\U0001f539 Goal: Transpose banana

// Transpose ka matlab hota hai —
// \U0001f449 Rows ko Columns me badal dena.
// Ya fir, matrix[i][j] aur matrix[j][i] ko swap kar dena.

// Lekin agar har element ko dono taraf se swap kar doge (double swap),
// to original hi reh jayega \U0001f605
// isiliye hum j = i se start karte hain.

//Kyuki:

// reverse() function poori row ko khud hi reverse kar deta hai

// Hume manually j loop lagake swap() karne ki zarurat nahi

// i bas row number batata hai ki ab kis row ko reverse karna hai