class Solution {
public: 
vector<int>nextSmaller( vector<int>& heights , int n){
    stack<int>s;
    vector<int>Ans(n);
    s.push(-1);
    for( int i = n-1 ; i>=0 ; i--){
        int curr = heights[i];
        while( s.top() != -1   &&  heights[s.top()]>= curr){
            s.pop();
        }
        Ans[i] = s.top();
        s.push(i);
    }
    return Ans;
}
 vector<int>prevsmaller(vector<int>& heights , int n){
    stack<int>s;
    vector<int>Ans(n);
    s.push(-1);
    for( int i = 0 ; i<n ; i++){
        int curr = heights[i];
        while( s.top() != -1 && heights[s.top()] >= curr){
            s.pop();
        }
        Ans[i] = s.top();
        s.push(i);
    }
    return Ans;
 }
   int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
         vector<int>next(n);
        next = nextSmaller(heights , n);
        vector<int>prev(n);
         prev = prevsmaller(heights , n);

       int Area = INT_MIN;
       for( int i = 0 ; i<n ; i++){
            int l = heights[i];

            if( next[i]== -1){
                next[i] = n;
            }

            int b = next[i] - prev[i] -1 ;
             int newArea = l*b;
             Area = max(newArea , Area);
       }
      return Area; 
    }
};