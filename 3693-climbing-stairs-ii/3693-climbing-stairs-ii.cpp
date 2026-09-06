class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        
        // dp[i] = minimum cost required to reach step i
        vector<int> dp(n + 1, INT_MAX);

        // We start from step 0 with cost 0
        dp[0] = 0;

        // Calculate minimum cost for every step
        for (int i = 1; i <= n; i++) {

            // Try jumping from i-1 to i
            if (i - 1 >= 0) {
                dp[i] = min(
                    dp[i],
                    dp[i - 1] + costs[i - 1] + 1
                );
            }

            // Try jumping from i-2 to i
            if (i - 2 >= 0) {
                dp[i] = min(
                    dp[i],
                    dp[i - 2] + costs[i - 1] + 4
                );
            }

            // Try jumping from i-3 to i
            if (i - 3 >= 0) {
                dp[i] = min(
                    dp[i],
                    dp[i - 3] + costs[i - 1] + 9
                );
            }
        }

        // Minimum cost to reach step n
        return dp[n];
    }
};