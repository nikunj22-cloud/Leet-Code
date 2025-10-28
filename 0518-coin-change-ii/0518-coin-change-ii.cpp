class Solution {
public:
    int n;
    int t[301][5001];
    
    int solve(int i, vector<int>& coins, int amount) {
        
        if(amount == 0)
            return t[i][amount] = 1; //amount 0 bnane ka toh 1 hee method h 
        
        if(i == n || amount < 0)
            return 0;
         //\U0001f539 Ab condition samjho:
// \U0001f449 if (i == n)

// Matlab:

// Hum last coin ke aage pahunch gaye hain,
// aur ab aur coin bacha hi nahi hai choose karne ke liye.

// \U0001f539 Example:

// coins = [1,2,5],
// n = 3

// To valid indexes hain: 0, 1, 2
// Agar recursion call me i = 3 ho gaya,
// matlab hum saare coins use kar chuke — ab aage koi option nahi bacha.

// Is case me:

// Agar amount bhi 0 ho gaya → perfect, ek combination mil gaya ✅

// Agar amount abhi bhi positive hai → paisa nahi bana sakte ❌
         if(t[i][amount] != -1)
            return t[i][amount];
        
        if(coins[i] > amount)
            return t[i][amount] = solve(i+1, coins, amount);
            //Agar current coin ki value coins[i] amount se zyada hai, toh yeh coin use hi nahi kar sakte.
        
        int take = solve(i, coins, amount-coins[i]);
        int skip = solve(i+1, coins, amount);
        
        return t[i][amount] = take+skip;
        
    }
    
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(0, coins, amount);
    }
};