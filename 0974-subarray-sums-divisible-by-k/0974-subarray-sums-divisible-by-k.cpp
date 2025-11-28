class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
          unordered_map<int , int >mp ;
          mp[0] = 1;
          int n = nums.size();
           int cnt = 0;
            int sum = 0;
          for( int i = 0 ; i< n ; i++){
                 sum += nums[i];
                 int rem = sum % k ;
                 if( rem < 0) rem += k;
                 if( mp.find( rem) != mp.end()){
                    cnt += mp[rem];
                 }
               mp[rem]++;
          }
          return cnt;
    }
};

//Asli fayda yahin hai:

// Maan lo:

// k = 5

// Situation:
// Prefix sum till i  = 14  → 14 % 5 = 4
// Prefix sum till j  = 19  → 19 % 5 = 4   (same remainder)


// Ab beech ka subarray sum hoga:

// 19 - 14 = 5


// Aur:

// 5 % 5 = 0 ✅

// 🔥 Yani:

// Same remainder milte hi guarantee ho jati hai
// ki beech wala subarray perfectly k se divisible hoga.