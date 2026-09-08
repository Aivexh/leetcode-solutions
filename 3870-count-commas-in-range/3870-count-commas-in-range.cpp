class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // Every number >= 1000 gets one extra comma
        for (long long place = 1000; place <= n; place *= 1000) {
            ans += n - place + 1;

            // Prevent overflow
            if (place > n / 1000)
                break;
        }

        return ans;
    }
};