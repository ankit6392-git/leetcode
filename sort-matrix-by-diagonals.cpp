class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // bottom-left (incl. main): non-increasing
        for (int start = n - 2; start >= 0; --start) {
            int i = start, j = 0;
            vector<int> d;
            while (i < n && j < n) d.push_back(grid[i++][j++]);
            sort(d.begin(), d.end());
            i = start; j = 0;
            for (auto it = d.rbegin(); it != d.rend(); ++it) {
                grid[i++][j++] = *it;
            }
        }

        // top-right: non-decreasing
        for (int start = n - 2; start > 0; --start) {
            int i = start, j = n - 1;
            vector<int> d;
            while (i >= 0 && j >= 0) d.push_back(grid[i--][j--]);
            sort(d.begin(), d.end());
            i = start; j = n - 1;
            for (auto it = d.rbegin(); it != d.rend(); ++it) {
                grid[i--][j--] = *it;
            }
        }

        return grid; 
    }
};
