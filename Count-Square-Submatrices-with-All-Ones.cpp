class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
      int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int total = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;  // First row/col → only 1x1 square
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                total += dp[i][j];
            }
        }
    }
    return total;  
        
    }
};
