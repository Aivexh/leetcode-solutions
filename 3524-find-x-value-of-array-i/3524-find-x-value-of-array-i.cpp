class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0);
        vector<long long> ans(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);

            int rem = num % k;

            // Subarray containing only num
            ndp[rem]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0)
                    continue;

                int newRem = (r * rem) % k;
                ndp[newRem] += dp[r];
            }

            dp = ndp;

            // Add all subarrays ending at current index
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};