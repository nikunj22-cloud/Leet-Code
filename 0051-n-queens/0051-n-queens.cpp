class Solution {
public: 
vector<vector<string>>result;
int N;
bool isValid( vector<string>& board , int row , int col){
    //check from the upper case
    for( int i = row-1 ; i >= 0  ; i-- ){
        if( board[i][col]=='Q'){
            return false;
        }
    }
        //check for diagonal left case
        for( int i = row-1  , j = col - 1 ; i>=0 && j>= 0 ; i-- , j--){
            if( board[i][j]=='Q'){
                return false;
            }
        }
            for( int i = row-1 ,  j = col+1 ; i>=0 && j<N ; i--, j++){
                if(board[i][j]=='Q'){
                    return false;
                }
            }
        
    return true;
}

void solve( vector<string>& board ,  int row){
        if( row>= N){ //mtlb  hm traverse krke last row tk phuch gye h or hmare sabhi row m q valid jgh pr rkhi gyi h
        //it is also the base case of the question
        result.push_back(board);
        return;
        }
        for( int col = 0 ; col< N ; col++){
            if( isValid( board , row , col)){
            board[row][col] ='Q';
            solve( board , row+1); //trust on recursion
              board[row][col]='.';
            }
        }
   }
    vector<vector<string>> solveNQueens(int n) {
              N = n;    
         vector<string>board( n  , string(n , '.')); //total n string h jinme n char h
       
        solve( board , 0);
        return  result; //time complexity factorial n and O(n) 
        //space complexity o(n)*o(n)
    }
};