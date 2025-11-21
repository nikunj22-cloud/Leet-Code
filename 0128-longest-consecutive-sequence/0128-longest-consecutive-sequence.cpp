class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st( nums.begin() , nums.end());
        //set k ander unique set dalne ka tarika 
        int ans = 0;
        for( int i = 0 ; i<nums.size() ; i++){
            if( st.find(nums[i]) != st.end()){
                st.erase( nums[i]);
            }
            int next = nums[i]+1;
            int prev = nums[i]-1;

            while( st.find(next) != st.end()){
                st.erase(next);
                next++;
            }
            while( st.find(prev) != st.end()){
                st.erase(prev);
                prev--;
            }
            ans = max( ans , next-prev-1);
        }
    return ans;
    }
};
//bhai yad rkhna or kisi m ni hoga ans m next-prev-1 hoga 
//Example se clear karte hain

// Suppose sequence hai:

// [1, 2, 3, 4, 5]


// maan lo current nums[i] = 3

// After while loops:
// prev = 0   (kyunki 1 ke baad 0 nahi mila)
// next = 6   (kyunki 5 ke baad 6 nahi mila)


// Ab actual consecutive numbers hain:

// 1, 2, 3, 4, 5


// Length = 5

// Formula:

// next - prev - 1
// = 6 - 0 - 1
// = 5 ✅

// General Math Logic