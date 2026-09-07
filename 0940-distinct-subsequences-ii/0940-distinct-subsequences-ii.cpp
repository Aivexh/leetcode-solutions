class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        // dp[i] = number of distinct subsequences
        // including the empty subsequence
        long long dp = 1;

        // last[c] = dp value before the previous occurrence
        // of character c
        vector<long long> last(26, 0);

        for (char ch : s) {
            int c = ch - 'a';

            long long newDp = (2 * dp) % MOD;

            // Remove subsequences that were already created
            // when we saw this character before.
            newDp = (newDp - last[c] + MOD) % MOD;

            // Save current dp for future duplicate handling
            last[c] = dp;

            dp = newDp;
        }

        // Remove the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};