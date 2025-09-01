class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
           auto pr = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };

        
        priority_queue<array<double,3>> pq;
        for (auto &c : classes) {
            pq.push({pr(c[0], c[1]), (double)c[0], (double)c[1]});
        }

        
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            double p = top[1], t = top[2];
            p += 1; t += 1;
            pq.push({pr((int)p, (int)t), p, t});
        }

        // Compute final average pass ratio
        double sum = 0.0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            sum += top[1] / top[2];
        }

        return sum / classes.size();
    }
};
