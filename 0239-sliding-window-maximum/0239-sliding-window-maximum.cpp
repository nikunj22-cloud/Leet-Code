class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>result;
        deque<int>deq;
        for( int i = 0 ; i<n ; i++){
           //window ka size k se bda nhi hona chahiye 
           while( !deq.empty() && deq.front() <= i-k){
            deq.pop_front();
           }
           //step2 make bigger element on the front for that we have to pop the whole bigger elment example 2
            while( !deq.empty()  &&  nums[i] >  nums[deq.back()]){
                //aane wala nums element deq main dale hue element se bda nikl gya ab bda nikl gya toh kya usko front main lana h toh isliye sabhi peeche pde element nikal do then push kro
                deq.pop_back();
            }
            deq.push_back(i);
            if( i >= k-1){
                result.push_back( nums[deq.front()]);
            }//deq.front is index see the line 17 index push kiya ja rha h 

        }
        return result;
    }
};
    //example  5 aaya deq m 3,2,1 pde h phle se hee toh inko nikalna pdega ab kyoki deq m front element sabse bda hoga toh yeh element peeche pde honge jinko delte krna hoga