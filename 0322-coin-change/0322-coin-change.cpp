class Solution {
public:
     int t[10001];
    int solve(vector<int>& coins, int amount) {
        if (amount < 0) return INT_MAX; // invalid
        if (amount == 0) return 0;      // base case

        if (t[amount] != -1) return t[amount]; // already computed

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = solve(coins, amount - coins[i]);
            if (ans != INT_MAX) {
                mini = min(mini, ans + 1); //consider amout-coins[i]
            }
        }

        return t[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset( t , -1 , sizeof(t)); // initialize memo table

        int ans = solve(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
