class Solution {
public:
   void dfs(vector<vector<int>>& image, int r , int c , int oldcolor , int newcolor){
    if(r < 0  || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != oldcolor ){
        return; //over bound ki condition or joh color assign kiya thaa check k liye woh hee same nhi nikla
    }
    image[r][c] = newcolor; //image cell ko new color se fill kro
    dfs(image , r-1 , c , oldcolor , newcolor);
    dfs(image , r+1 , c , oldcolor , newcolor);
    dfs( image , r , c-1 , oldcolor , newcolor);
    dfs( image , r , c+1 , oldcolor , newcolor);
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         if( image[sr][sc] == color){
            return image ;
         }//if already image jis color se paint honi chhaiye painted h

          int oldcolor = image[sr][sc];
          dfs( image , sr , sc , oldcolor , color);

          return image;
    }
};