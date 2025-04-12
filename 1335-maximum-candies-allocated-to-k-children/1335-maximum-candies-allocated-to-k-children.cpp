class Solution {
public:
    bool canDist(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int i = 0; i < candies.size(); i++) {
            count += candies[i] / mid;
            if (count >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = 0;
        for (int i = 0; i < candies.size(); i++) {
            r = max(r, candies[i]);
        }

        int result = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canDist(candies, k, mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
