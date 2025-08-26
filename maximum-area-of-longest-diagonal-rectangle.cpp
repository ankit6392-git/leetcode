class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long bestD2 = -1, bestArea = 0;
        for (auto &rc : dimensions) {
            long long w = rc[0], h = rc[1], d2 = w*w + h*h, area = w*h;
            if (d2 > bestD2 || (d2 == bestD2 && area > bestArea)) {
                bestD2 = d2;
                bestArea = area;
            }
        }
        return (int)bestArea;
    }
};
