class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> st; // will store indices of days

        for (int i = n - 1; i >= 0; i--) {
            // Pop all days that are not warmer
            while (!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }

            // If stack not empty, next warmer day is on top
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            // Push current index
            st.push(i);
        }

        return ans;
    }
};
