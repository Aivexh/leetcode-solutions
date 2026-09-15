class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[l][r] = true if s[l...r] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Find all palindromic substrings
        for (int r = 0; r < n; r++) {
            for (int l = r; l >= 0; l--) {

                if (s[l] == s[r] &&
                    (r - l <= 2 || pal[l + 1][r - 1])) {

                    pal[l][r] = true;
                }
            }
        }

        // dp[i] = maximum number of valid substrings
        // using the first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {

            // Don't choose a substring ending at i
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // Try every palindrome ending at i
            for (int l = 0; l <= i; l++) {

                int len = i - l + 1;

                if (len >= k && pal[l][i]) {
                    dp[i + 1] = max(dp[i + 1], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};