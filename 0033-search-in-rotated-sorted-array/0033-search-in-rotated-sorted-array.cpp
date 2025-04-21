class Solution {
public:
    int search(vector<int>& arr, int target) {
         int  i = 0;
         int j = arr.size()-1;

         while( i<=j){
            int mid = i + (j-i)/2;
            if( arr[mid]==target){
                return  mid ;
            }
            //left sorted toh left pr binary search lgao
            if( arr[i] <= arr[mid]){
            //check krlo left m mera target element h ya nhi agr nhi toh move right of left 
            if( arr[i] <= target && target <= arr[mid]){
                j = mid-1;
            }
            else{
                i = mid+1;
            }

            }
            else{
             //right sorted h toh right pr binary seach lgao
             if(mid <= target && target <= arr[j]){
                //check krlo right m mera target element h ya nhi agr nhi toh move left of right
               i = mid+1;
             }
             else{
                j = mid-1;
             }

            }
         }
         return -1;
    }
};