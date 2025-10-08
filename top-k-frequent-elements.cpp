class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        // Max heap (frequency, element)
        priority_queue<pair<int, int>> pq;
        for (auto& [num, count] : freq)
…    }
};
