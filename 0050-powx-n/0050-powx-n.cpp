class Solution {
public:
    double overflowsebachna( double x , long n){ //long overflow se bachne k liye 2ki power -31 se +31 tk
        if( n == 0){
            return 1;
        }
        if( n < 0){
           return  overflowsebachna( 1/x , -n);
        }
        if( n%2 == 0)
            return  overflowsebachna( x*x , n/2);
            return   x*overflowsebachna(x*x , (n-1)/2);
        
    }
    double myPow(double x, int n) {
        return overflowsebachna( x , (long)n);
    }
};