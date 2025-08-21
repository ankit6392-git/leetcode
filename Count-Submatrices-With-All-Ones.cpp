class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
         int n = mat.size(), m = mat[0].size();
    vector<int> height(m, 0);
    int res = 0;

    for (int i = 0; i < n; i++) {
        // Step 1: Build histogram heights
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) height[j] = 0;
            else height[j] += 1;
        }

        // Step 2: Use monotonic stack to count submatrices
        stack<int> st;
        vector<int> sum(m, 0);

        for (int j = 0; j < m; j++) {
            while (!st.empty() && height[st.top()] >= height[j]) st.pop();

            if (!st.empty()) {
                int prev = st.top();
                sum[j] = sum[prev] + height[j] * (j - prev);
            } else {
                sum[j] = height[j] * (j + 1);
            }

            st.push(j);
            res += sum[j];
        }
    }

    return res;
    }
};
