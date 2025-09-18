class Solution {
public:
    vector<int> nextsmaller(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top(); // index of next smaller
            }
            st.push(i); // push index
        }
        return ans;
    }

    vector<int> prevsmaller(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top(); // index of prev smaller
            }
            st.push(i); // push index
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextsmaller(heights, n);
        vector<int> prev = prevsmaller(heights, n);

        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1) next[i] = n; // if no smaller on right
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
};
