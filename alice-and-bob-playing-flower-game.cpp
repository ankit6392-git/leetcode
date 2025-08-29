class Solution {
public:
    long long flowerGame(int n, int m) {
         long long odd_red = (n + 1) / 2;   // ceil(n/2)
        long long even_red = n / 2;        // floor(n/2)
        long long odd_blue = (m + 1) / 2;  // ceil(m/2)
        long long even_blue = m / 2;       // floor(m/2)

        return odd_red * even_blue + even_red * odd_blue;
    }
};
