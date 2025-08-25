class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        
        int m = mat.size(), n = mat[0].size();
        vector<int> result(m * n);
        
        int row = 0, col = 0, dir = 1; // dir=1 means up-right, -1 means down-left
        
        for (int i = 0; i < m * n; i++) {
            result[i] = mat[row][col];
            
            if (dir == 1) { // Moving up-right
                if (col == n - 1) { row++; dir = -1; }
                else if (row == 0) { col++; dir = -1; }
                else { row--; col++; }
            } else { // Moving down-left
                if (row == m - 1) { col++; dir = 1; }
                else if (col == 0) { row++; dir = 1; }
                else { row++; col--; }
            }
        }
        
        return result;
    }
};
